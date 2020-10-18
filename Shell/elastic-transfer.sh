# !/bin/bash

usage()
{
    echo "usage: elastic-transfer http://10.0.0.1:9201 http://10.0.0.2:9201 countries " >&2
    exit 1
}

[ "$#" -lt 1 ] && usage

INPUT=$1
OUTPUT=$2
INDEX=$3

print_status(){
    KEY=$1
    TYPE=$2
    echo "${KEY} get ${TYPE}..."
}

transfer(){
    KEY=$1

    print_status $KEY "settings"

    elasticdump \
        --input=$INPUT/$KEY \
        --output=$OUTPUT/$KEY \
        --type=settings

    print_status $KEY "analyzer"

    elasticdump \
        --input=$INPUT/$KEY \
        --output=$OUTPUT/$KEY \
        --type=analyzer

    print_status  $KEY "mapping"

    elasticdump \
        --input=$INPUT/$KEY \
        --output=$OUTPUT/$KEY \
        --type=mapping

    print_status $KEY "data"

    elasticdump \
        --input=$INPUT/$KEY \
        --output=$OUTPUT/$KEY \
        --type=data

    print_status $KEY "alias"

    elasticdump \
        --input=$INPUT/$KEY \
        --output=$OUTPUT/$KEY \
        --type=alias

}

if [ "$INDEX" = "" ]
    then
        KEY=$(curl $INPUT/_all | jq  'keys' | tr -d "\n" | tr -d '"' | sed 's:^.\(.*\).$:\1:' )
        IFS=',' read -ra KEYS <<< "$KEY"

        for k in "${KEYS[@]}"
        do
            transfer $k
        done
    else
        KEY=$(curl $INPUT/$INDEX | jq 'keys | .[0]'| tr -d '"' )
        transfer $KEY
fi
