build: tccopy.cpp tcpaste.cpp
	mkdir -p build
	g++ tccopy.cpp -lterminalclipboard -o build/tccopy
	g++ tcpaste.cpp -lterminalclipboard -o build/tcpaste
	g++ tcclear.cpp -lterminalclipboard -o build/tcclear

buildlib: lib/libterminalclipboard.cpp
	mkdir -p build-lib
	g++ -shared lib/libterminalclipboard.cpp -o build-lib/libterminalclipboard.so -fPIC

installlib: buildlib
	cp build-lib/libterminalclipboard.so /usr/lib
	cp lib/libterminalclipboard.hpp /usr/include

install: build
	cp build/tccopy /usr/local/bin
	cp build/tcpaste /usr/local/bin
	cp build/tcclear /usr/local/bin

uninstall:
	rm /usr/local/bin/tccopy
	rm /usr/local/bin/tcpaste
	rm /usr/local/bin/tcclear

uninstalllib:
	rm /usr/lib/libterminalclipboard.so
	rm /usr/include/libterminalclipboard.hpp

clean:
	rm -rf build
	rm -rf build-lib