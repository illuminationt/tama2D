#ifndef TEXTDX_H
#define TEXTDX_H

#include<Windows.h>
#include"Graphics.h"
#include<string>
#include"Constants.h"

class TextDX {
private:
	Graphics* m_graphics;
	DWORD m_color;
	LPD3DXFONT m_dxFont;
	RECT m_fontRect;

	D3DXMATRIX m_matrix;//回転のため
	float m_angle;//回転角

public:
	TextDX();
	virtual ~TextDX();

	virtual bool initialize(
		Graphics* g,
		DWORD color=0xffffffff,
		int height=30,
		bool bold=false,
		bool italic=false,
		const std::string& fontName="Arial");

	//(x,y)にstrを描画。返り値...失敗:0 成功:テキストの高さ
	virtual int print(const std::string& str, int x, int y);
	//rect内に指定のformatで描画
	virtual int print(const std::string& str, RECT& rect, UINT format);
	

	virtual void onLostDevice();
	virtual void onResetDevice();

	//ゲット関数群
	virtual float degrees();
	virtual float radians();
	virtual DWORD fontColor();

	//セット関数群
	virtual void setDegrees(float deg);
	virtual void setRadians(float rad);
	virtual void setFontColor(DWORD c);









};

















#endif