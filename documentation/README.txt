
.keep for any empty folders I want git to track

Folder layout
./build // Build project here meson build && ninja -C build
./dist // Any files for distributation get placed here after build { will set up with meson in future }
    ./bin // Binaries
    ./lib // Libraries
    ./include // Includes
    ./share // Everything else
./doc // Any documentation goes here
./dump // Plase any unused by interesting related code here so not to pulute the projects source tree
./src // Projects source files non library impl header files
./thirdparty // any third party deps that I can include with the build process or statically link to.