#pragma once
class Cimage
{
private:
	/*	��� �̹��� �̹����Ŵ����� �߰��ϴ� �뵵	*/
	/*	��� �̹��� �̹����Ŵ����� �߰��ϴ� �뵵	*/
	/*	��� �̹��� �̹����Ŵ����� �߰��ϴ� �뵵	*/
	/*	��� �̹��� �̹����Ŵ����� �߰��ϴ� �뵵	*/
	/*	��� �̹��� �̹����Ŵ����� �߰��ϴ� �뵵	*/
public:
	Cimage();
	~Cimage();

	virtual HRESULT init();

	//�ʿ������� ���� ������
	virtual void release();
	virtual void update();
	virtual void render();
};

