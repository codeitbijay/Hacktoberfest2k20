# curl (REST API)
# Assuming "anonymous read access" has been enabled on your Jenkins instance.

# How to use
# `sh linter.sh your-jenkinsfile-path`

# need input your Jenkins login username and password below.
# this file is ignored in git so it will appare your git workspace.
username=admin
password=admin
JENKINS_URL=http://localhost:8080/

PWD=`pwd`
JENKINS_FILE=$1

# JENKINS_CRUMB is needed if your Jenkins master has CRSF protection enabled as it should
# JENKINS_CRUMB=`curl "$JENKINS_URL/crumbIssuer/api/xml?xpath=concat(//crumbRequestField,\":\",//crumb)"`
# curl -X POST -H $JENKINS_CRUMB -F "jenkinsfile=<Jenkinsfile" $JENKINS_URL/pipeline-model-converter/validate
curl --user $username:$password -X POST -F "jenkinsfile=<$PWD/$JENKINS_FILE" $JENKINS_URL/pipeline-model-converter/validate