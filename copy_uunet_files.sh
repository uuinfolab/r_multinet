cd src

cp -r ../ext/uunet/src src
cp -r ../ext/uunet/libs libs
cp -r ../ext/uunet/ext/infomap infomap
cp -r ../ext/uunet/ext/eclat eclat
cp -r ../ext/uunet/ext/eigen3 eigen3

# build Makevars
printf "SOURCES=" > sources
ls | grep "\.cpp$" >> sources
find src/* | grep "\.cpp$" >> sources
find libs/* | grep "\.cpp$" >> sources
find infomap/* | grep "\.cpp$" >> sources
find eclat/* | grep "\.c$" >> sources
printf "OBJECTS=" > objects
ls | grep "\.cpp$" | sed 's/cpp$/o/g' >> objects
find src/* | grep "\.cpp$" | sed 's/cpp$/o/g' >> objects
find libs/* | grep "\.cpp$" | sed 's/cpp$/o/g' >> objects
find infomap/* | grep "\.cpp$" | sed 's/cpp$/o/g' >> objects
find eclat/* | grep "\.c$" | sed 's/c$/o/g' >> objects

cat ../make/Makevars > Makevars
printf "\n" >> Makevars
tr '\n' ' ' < sources >> Makevars
printf "\n" >> Makevars
tr '\n' ' ' < objects >> Makevars

cat ../make/Makevars.win > Makevars.win
printf "\n" >> Makevars.win
tr '\n' ' ' < sources >> Makevars.win
printf "\n" >> Makevars.win
tr '\n' ' ' < objects >> Makevars.win

rm sources
rm objects
# copy external libraries
##mkdir lib
##cp -r ../../../C++/ext/eigen3 lib
##cp -r ../../../C++/ext/infomap lib
# copying the .h files from the eclat library
##mkdir lib/eclat
##find ../../../C++/ext/eclat* | grep "\\.h$" | sed 's/^/cp /g' | sed 's/$/ lib\/eclat/g' > f
##chmod +x f
##./f
##rm f
