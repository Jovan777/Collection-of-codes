# Aerospike Third Party Dependencies

This package contains Windows third-party libraries and header files that are 
prerequisites for the Aerospike C client build.  This package is only designed 
to help build the Aerospike C client library on Windows.

Separate deployment packages (aerospike-client-c, aerospike-client-c-libuv and 
aerospike-client-c-libevent) are used to build customer applications with Aerospike.

## libuv 1.15.0

libuv is required if using async methods and libuv is the chosen event framework.
libuv is the recommended event framework on Windows.

- include
	- tree.h
	- uv.h
	- uv-errno.h
	- uv-threadpool.h
	- uv-version.h
	- uv-win.h
- lib/x64
	- Debug/libuv.dll
	- Debug/libuv.lib
	- Debug/libuv.pdb
	- Release/libuv.dll
	- Release/libuv.lib

## libevent 2.1.8

libevent is required if using async methods and libevent is the chosen event framework.

- include
	- evdns.h
	- event.h
	- evhttp.h
	- evrpc.h
	- evutil.h
	- event2 folder
- lib/x64
	- Debug/event_core.dll
	- Debug/event_core.lib
	- Debug/event_core.pdb
	- Release/event_core.dll
	- Release/event_core.lib

## lua 5.1.5

Lua is required if using aggregation queries.

- include
	- lauxlib.h
	- lua.h
	- luaconf.h
	- lualib.h
- lib/x64
	- Debug/lua51.dll
	- Debug/lua51.lib
	- Debug/lua51.pdb
	- Release/lua51.dll
	- Release/lua51.lib

## pthreads 2.10.0

Pthreads are required.

- include
	- pthread.h
	- sched.h
	- semaphore.h
	- _ptw32.h
- lib/x64
	- Debug/pthreadVC2d.dll
	- Debug/pthreadVC2d.lib
	- Debug/pthreadVC2d.pdb
	- Release/pthreadVC2.dll
	- Release/pthreadVC2.lib

## openssl 1.0.2

OpenSSL is required if using TLS/SSL sockets.

- include
	- openssl folder
- lib/x64
	- Debug/libeay32.dll
	- Debug/libeay32.lib
	- Debug/libeay32.pdb
	- Debug/ssleay32.dll
	- Debug/ssleay32.lib
	- Debug/ssleay32.pdb
	- Release/libeay32.dll
	- Release/libeay32.lib
	- Release/ssleay32.dll
	- Release/ssleay32.lib

## zlib 1.2.8.8

zlib is required.

- include
	- crc32.h
	- deflate.h
	- gzguts.h
	- inffast.h
	- inffixed.h
	- inflate.h
	- inftrees.h
	- trees.h
	- zconf.h
	- zlib.h
	- zutil.h
- lib/x64
	- Debug/zlibd.dll
	- Debug/zlibd.lib
	- Debug/zlibd.pdb
	- Release/zlib.dll
	- Release/zlib.lib

## getopt 1.0.2

getopt is required for aerospike-test, examples and benchmark programs that 
parse command-line arguments.

- include
	- getopt.h
- lib/x64
	- Debug/getopt.dll
	- Debug/getopt.lib
	- Debug/getopt.pdb
	- Release/getopt.dll
	- Release/getopt.lib
