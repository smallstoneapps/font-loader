# SDK Variables
SDK_VERSION=3.12
SDK_NAME=sdk-core
SDK_ZIP_NAME=$SDK_NAME-$SDK_VERSION.tar.bz2

## Download and extract the SDK core
wget --quiet https://s3.amazonaws.com/assets.getpebble.com/sdk3/release/$SDK_ZIP_NAME
tar -zxf $SDK_ZIP_NAME

# Clean out any existing header files
mkdir -p tests/include
rm tests/include/*.h

# Copy the Ap;ite headers to the folder and make some other ones
cp $SDK_NAME/pebble/aplite/include/pebble.h tests/include/
cp $SDK_NAME/pebble/aplite/include/pebble_fonts.h tests/include/
cp $SDK_NAME/pebble/aplite/include/gcolor_definitions.h tests/include/
touch tests/include/pebble_warn_unsupported_functions.h
echo "typedef size_t time_t;\n" > tests/include/time.h

# Cleanup
rm -rf $SDK_NAME
rm $SDK_ZIP_NAME
