#pragma once

/*
	ҳ�����ݽṹ
*/
class PageFrame {
private:
	int pid; // ������һ�����̵�����
	unsigned va; // ���ڽ��̵������ַ��ֵֻ��ptn������ҳ���滻ʱ����ԭ���̵�ҳ��
public:
	PageFrame() {
		pid = 0;
		va = -1;
	}
	PageFrame(int id, unsigned v) {
		pid = id;
		va = v;
	}
	bool operator==(const PageFrame & frame) {
		return pid == frame.pid;
	}
	int getPid() const {
		return pid;
	}
	int getVa() const {
		return va;
	}
};