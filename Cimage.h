#pragma once
class Cimage
{
private:
	float m_imageSize;
	/*	모든 이미지 이미지매니저에 추가하는 용도	*/
	/*	모든 이미지 이미지매니저에 추가하는 용도	*/
	/*	모든 이미지 이미지매니저에 추가하는 용도	*/
	/*	모든 이미지 이미지매니저에 추가하는 용도	*/
	/*	모든 이미지 이미지매니저에 추가하는 용도	*/
public:
	Cimage();
	~Cimage();

	virtual HRESULT init();

	//필요할지도 몰라서 만들어둠
	virtual void release();
	virtual void update();
	virtual void render();
};

