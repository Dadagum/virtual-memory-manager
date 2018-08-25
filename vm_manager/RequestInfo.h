#pragma once

/*
	进程访问信息
*/
class RequestInfo {
public:
	int pNumber;
	int fNumber;
	bool tlbHit;
	bool ptHit;
	RequestInfo() {
		pNumber = 0;
		fNumber = 0;
		tlbHit = false;
		ptHit = false;
	}
};