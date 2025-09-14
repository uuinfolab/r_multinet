cd src

rm -rf src
rm -rf infomap
rm -rf eclat
rm -rf boost

#cp -r ../ext/uunet/src src
cp -r ../ext/uunet/src src
cp -r ../ext/uunet/ext/infomap infomap
cp -r ../ext/uunet/ext/boost boost
cp ../C++/* .

# build Makevars
printf "SOURCES=" > sources
ls | grep "\.cpp$" >> sources
find src/* | grep "\.cpp$" >> sources
find infomap/* | grep "\.cpp$" >> sources
printf "OBJECTS=" > objects
ls | grep "\.cpp$" | sed 's/cpp$/o/g' >> objects
find src/* | grep "\.cpp$" | sed 's/cpp$/o/g' >> objects
find infomap/* | grep "\.cpp$" | sed 's/cpp$/o/g' >> objects

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
