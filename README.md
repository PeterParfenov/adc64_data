# adc64_data

## Install

1. Download repository from github:

        git clone https://github.com/PeterParfenov/adc64_data.git

2. Go to a downloaded repository:

        cd <path>/adc64_data/

3. Create build directory:

        mkdir build
        cd build

4. Link source files via cmake:

        cmake ../src/

5. Install project via make:

        make

## Usage

In the build directory:

        cd <path>/adc64_data/build/

Use executable file Main with arguments:

        ./Main -i <path_1>/inputfile.root -o <path_2>/outputfile.root