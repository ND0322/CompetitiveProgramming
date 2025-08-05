#!/bin/bash

# Compile the C++ program
echo "Compiling program..."
g++ -O2 -march=native main.cpp -o program
if [ $? -ne 0 ]; then
    echo "Compilation failed!"
    exit 1
fi

# Create results directory
mkdir -p benchmark_results

# Test cases
test_cases=(500000)

# Warm-up run
echo "Running warm-up..."
python3 main.py <<< "1000" > /dev/null
./program < input.txt > /dev/null

# Benchmark loop
for n in "${test_cases[@]}"; do
    echo -e "\nBenchmarking n = $n"

    
    # Run 5 times and capture timings
    for i in {1..5}; do
        echo -n "Run $i: "
        
        # BSD/macOS compatible timing
        start=$(python3 -c 'import time; print(time.time())')
        ./program < input.txt > /dev/null
        end=$(python3 -c 'import time; print(time.time())')
        runtime=$(echo "$end - $start" | bc)
        
        # Save results
        echo "$n,$i,$runtime" >> benchmark_results/results.csv
        echo "  $runtime seconds"
    done
    

done

echo -e "\nBenchmark complete! Results saved to benchmark_results/results.csv"