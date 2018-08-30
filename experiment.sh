#!/bin/bash

rm -f *.o dict1 dict2
echo "Making dict1 and dict2"
make dict1 -B
make dict2 -B

num_of_testdata=(1000 2000 3000 4000 5000 6000 7000 8000)
num_of_test=1
num_of_key=100

for data in ${num_of_testdata[@]}
do
    echo "Test random data with size =" $data ":"
    total1=0.0
    total2=0.0
    iter=0
    while(($iter<$num_of_test))
    do
        shuf -n $data athlete_events_filtered.csv > datafile
        cat datafile | awk -F ',' '{print $2}' | shuf -n $num_of_key > keyfile
        #cat athlete_events_filtered.csv | awk -F ',' '{print $2}' | shuf -n $num_of_key > keyfile
        
        dict1 datafile output1 < keyfile > stdout1
        dict2 datafile output2 < keyfile > stdout2
        
        result1=`cat stdout1 | awk -F '-->' '{sum += $2} END {print sum/NR}'`
        result2=`cat stdout2 | awk -F '-->' '{sum += $2} END {print sum/NR}'`
   
        echo "Test#"$iter", dict1: average=" $result1 ",dict2: average=" $result2 

        total1=`echo "$total1 + $result1"|bc`
        total2=`echo "$total2 + $result2"|bc`
        let "iter++"
    done
    total1=`echo "scale=2;$total1 / $num_of_test"|bc`
    total2=`echo "scale=2;$total2 / $num_of_test"|bc`
    echo "average of dict1:" $total1, "dict2:" $total2
    echo "-----------------------------------------------"
    echo
done

echo "================================================"
for data in ${num_of_testdata[@]}
do
    echo "Test sorted data with size =" $data ":"
    total1=0.0
    total2=0.0
    iter=0
    while(($iter<$num_of_test))
    do
        shuf -n $data athlete_events_filtered.csv |sort -t "," -k 2 -d > datafile
        #cat athlete_events_filtered.csv | awk -F ',' '{print $2}' | shuf -n $num_of_key > keyfile
        cat datafile | awk -F ',' '{print $2}' | shuf -n $num_of_key > keyfile
        
        dict1 datafile output1 < keyfile > stdout1
        dict2 datafile output2 < keyfile > stdout2
        
        result1=`cat stdout1 | awk -F '-->' '{sum += $2} END {print sum/NR}'`
        result2=`cat stdout2 | awk -F '-->' '{sum += $2} END {print sum/NR}'`
   
        echo "Test#"$iter", dict1: average=" $result1 ",dict2: average=" $result2 

        total1=`echo "$total1 + $result1"|bc`
        total2=`echo "$total2 + $result2"|bc`

        let "iter++"
    done
    total1=`echo "scale=2;$total1 / $num_of_test"|bc`
    total2=`echo "scale=2;$total2 / $num_of_test"|bc`
    echo "average of dict1:" $total1, "dict2:" $total2
    echo "-----------------------------------------------"
    echo
done
