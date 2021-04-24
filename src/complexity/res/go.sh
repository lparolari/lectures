g++ -O0 ./bench.cpp
chmod u+x ./a.out

pids=""

for i in `seq 0 5`; do
    ./a.out ASC >> res_asc.csv &
    pids="$pids $!"
done

wait $pids

pids=""

for i in `seq 0 5`; do
    ./a.out DESC >> res_desc.csv &
    pids="$pids $!"
done

wait $pids
