#pragma once

/*
	���̷�����Ϣ
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
		tlbHit = 0;
		ptHit = 0;
	}
};