#!/bin/bash

rm -f *.o dict1 dict2
echo "Making dict1 and dict2"
make dict1 -B
make dict2 -B

DATASIZE=(1000 2000 3000 4000 5000 6000 7000 8000)
TEST=1
KEYSIZE=100
FILE="athlete_events_filtered.csv"

for data in ${DATASIZE[@]}
do
    echo "Test random data with size =" $data ":"
    total1=0.0
    total2=0.0
    iter=0
    while(($iter<$TEST))
    do
        shuf -n $data $FILE > datafile
        cat datafile | awk -F ',' '{print $2}' | shuf -n $KEYSIZE > keyfile
        #cat $FILE | awk -F ',' '{print $2}' | shuf -n $KEYSIZE > keyfile
        
        dict1 datafile output1 < keyfile > stdout1
        dict2 datafile output2 < keyfile > stdout2
        
        result1=`cat stdout1 | awk -F '-->' '{sum += $2} END {print sum/NR}'`
        result2=`cat stdout2 | awk -F '-->' '{sum += $2} END {print sum/NR}'`
   
        echo "Test#"$iter", dict1: average=" $result1 ",dict2: average=" $result2 

        total1=`echo "$total1 + $result1"|bc`
        total2=`echo "$total2 + $result2"|bc`
        let "iter++"
    done
    total1=`echo "scale=2;$total1 / $TEST"|bc`
    total2=`echo "scale=2;$total2 / $TEST"|bc`
    echo "average of dict1:" $total1, "dict2:" $total2
    echo "-----------------------------------------------"
    echo
done

echo "================================================"
for data in ${DATASIZE[@]}
do
    echo "Test sorted data with size =" $data ":"
    total1=0.0
    total2=0.0
    iter=0
    while(($iter<$TEST))
    do
        shuf -n $data $FILE |sort -t "," -k 2 -d > datafile
        #cat $FILE | awk -F ',' '{print $2}' | shuf -n $KEYSIZE > keyfile
        cat datafile | awk -F ',' '{print $2}' | shuf -n $KEYSIZE > keyfile
        
        dict1 datafile output1 < keyfile > stdout1
        dict2 datafile output2 < keyfile > stdout2
        
        result1=`cat stdout1 | awk -F '-->' '{sum += $2} END {print sum/NR}'`
        result2=`cat stdout2 | awk -F '-->' '{sum += $2} END {print sum/NR}'`
   
        echo "Test#"$iter", dict1: average=" $result1 ",dict2: average=" $result2 

        total1=`echo "$total1 + $result1"|bc`
        total2=`echo "$total2 + $result2"|bc`

        let "iter++"
    done
    total1=`echo "scale=2;$total1 / $TEST"|bc`
    total2=`echo "scale=2;$total2 / $TEST"|bc`
    echo "average of dict1:" $total1, "dict2:" $total2
    echo "-----------------------------------------------"
    echo
done
