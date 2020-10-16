#!/bin/sh

# check that artifactory key is provided
if [ -z "${ARTIFACTORY_API_KEY}" ]; then
    echo "Artifactory: skip - API KEY is not provided for pull requests from forks";
    continue
fi

# get all builds paths (https://na.artifactory.swg-devops.com:443/iot-waw-trevis-generic-local/<BRANCH_NAME>/<BUILD_NUMBER>) older than ARTIFACTORY_KEEP_DAYS
endTime=$(date +%s%N -d "${ARTIFACTORY_KEEP_DAYS} day ago" | cut -b1-13)
echo "Getting all builds older than ${ARTIFACTORY_KEEP_DAYS} day(s)."
cmd="curl -s -X GET -H 'X-JFrog-Art-Api: '${ARTIFACTORY_API_KEY} \"https://na.artifactory.swg-devops.com/artifactory/api/search/creation?from=0&to=${endTime}&repos=iot-waw-trevis-generic-local\""
echo ${cmd}
result=`eval ${cmd}`
buildPaths=`echo ${result} | sed -e 's/uri" \: "/\n/g'  | sed -e 's/\(https:\/\/na.artifactory.swg-devops.com:443\/artifactory\/\)api\/storage\/\(iot-waw-trevis-generic-local\/[^\/]*\/[^\/]*\).*/\1\2/g' | sed -e '/{/d' | sort -u `
echo $buildPaths

# delete old builds
for buildPath in ${buildPaths}; do
    echo "-- Build ${buildPath} is too old so it will be deleted."
    cmd="curl -X DELETE -H 'X-JFrog-Art-Api: '${ARTIFACTORY_API_KEY} ${buildPath}"
    echo $cmd
    eval $cmd
done

# get all builds and branches
echo "Getting all builds and branches."
cmd="curl -X POST -H 'X-JFrog-Art-Api: '${ARTIFACTORY_API_KEY} -H 'content-type: text/plain' -d 'items.find({\"repo\":\"iot-waw-trevis-generic-local\", \"type\":\"folder\", \"depth\": {\"\$lte\": \"2\"}})' https://na.artifactory.swg-devops.com/artifactory/api/search/aql"
echo ${cmd}
result=`eval ${cmd}`
builds=`echo ${result} | sed -e 's/", "name" \: "/\//g' | sed -e 's/path" \: "/\n/g' | sed -e 's/", "type.*//g' | sed -e '/{/d' | sed -e '/^\./d' | sort -u`
branches=`echo ${result} | sed -e 's/", "name" \: "/\//g' | sed -e 's/path" \: "/\n/g' | sed -e 's/", "type.*//g' | sed -e '/{/d' | sed -e '/^\./!d' | sed -e '/^\.\/\./d' | sed -e 's/^\.\///g' | sort -u`

# get all non empty builds
echo "Getting all non empty builds."
cmd="curl -X POST -H 'X-JFrog-Art-Api: '${ARTIFACTORY_API_KEY} -H 'content-type: text/plain' -d 'items.find({\"repo\":\"iot-waw-trevis-generic-local\", \"type\":\"file\"})' https://na.artifactory.swg-devops.com/artifactory/api/search/aql"
echo ${cmd}
result=`eval ${cmd}`
nonEmptyBuilds=`echo ${result} | sed -e 's/path" \: "/\n/g' | sed -e 's/", "name.*//g' | sed -e '/{/d' | sed -e 's/\([^\/]*\/[^\/]*\).*/\1/g'| sort -u`

# iterate over branches
for branch in ${branches}; do
    nonEmptyBuildsInBranch=`echo ${nonEmptyBuilds} | sed -e 's/ /\n/g' | grep "\b${branch}\/"`

    # if grep returns 0 that means that branch has some non empty builds
    if [ "$?" -eq "0" ]; then
        echo "Branch ${branch} contains some files so iterate over builds and delete empty ones."

        # iterate over builds and check if each build is empty or not
        buildsInBranch=`echo ${builds} | sed -e 's/ /\n/g' | grep "\b${branch}\/"`
        for buildInBranch in ${buildsInBranch}; do
            nonEmptyBuildsInBranchNamedByBuild=`echo ${nonEmptyBuildsInBranch} | sed -e 's/ /\n/g' | grep "\b${buildInBranch}\b"`

            # if grep returns 0 that means that build has some files
            if [ "$?" -eq "0" ]; then
                echo "-- Build ${buildInBranch} contains some files so it won't be deleted."
            else
                echo "-- Build ${buildInBranch} does not contain any files so it will be deleted."
                # delete empty build
                cmd="curl -X DELETE -H 'X-JFrog-Art-Api: '${ARTIFACTORY_API_KEY} https://na.artifactory.swg-devops.com:443/artifactory/iot-waw-trevis-generic-local/${buildInBranch}"
                echo $cmd
                eval $cmd
            fi
        done
    else
        echo "Branch ${branch} does not contain any files so it will be deleted."
        # delete empty branch
        cmd="curl -X DELETE -H 'X-JFrog-Art-Api: '${ARTIFACTORY_API_KEY} https://na.artifactory.swg-devops.com:443/artifactory/iot-waw-trevis-generic-local/${branch}"
        echo $cmd
        eval $cmd
    fi
done