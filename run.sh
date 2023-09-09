set -u -e

# Compile it and output to executable called 'app'
clang++ -std=c++11 main.cpp -I/Library/Frameworks/SDL2.framework/Headers -I/Library/Frameworks/SDL2_image.framework/Headers -F/Library/Frameworks -framework SDL2 -framework SDL2_image -o app

# runs the app
./app