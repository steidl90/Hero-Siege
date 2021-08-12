#include "framework.h"
#include "animation.h"

animation::animation() :_frameNum(0), _frameWidth(0), _frameHeight(0), _loop(false),
_elapseSec(0), _nowPlayIndex(0), _play(false)
{
}

animation::~animation()
{
}

HRESULT animation::init(int totalW, int totalH, int frameW, int frameH)
{

	//°¡·Î ÇÁ·¹ÀÓ °¹¼ö
	_frameWidth = frameW;
	int frameWidthNum = totalW / _frameWidth;

	//¼¼·Î ÇÁ·¹ÀÓ °¹¼ö
	_frameHeight = frameH;
	int frameHeightNum = totalH / _frameHeight;

	//ÃÑ ÇÁ·¹ÀÓ ¼ö
	_frameNum = frameWidthNum * frameHeightNum;

	//ÇÁ·¹ÀÓ À§Ä¡ ¸ñ·Ï ¼ÂÆÃ ÇÏÀÚ.
	_frameList.clear();

	for (int i = 0; i < frameHeightNum; i++)
	{
		for (int j = 0; j < frameWidthNum; j++)
		{
			POINT framePos;
			framePos.x = j * _frameWidth;
			framePos.y = i * _frameHeight;

			//ÇÁ·¹ÀÓ À§Ä¡ ¸ñ·Ï Ãß°¡ÇÏ±â
			_frameList.push_back(framePos);
		}
	}

	//±âº» ÇÁ·¹ÀÓÀ¸·Î ¼ÂÆÃÇÏÀÚ.
	setDefPlayFrame();
	return S_OK;
}

void animation::setDefPlayFrame(bool reverse, bool loop)
{
	_loop = loop;
	_playList.clear();

	if (reverse)
	{
		if (_loop)
		{
			for (int i = 0; i < _frameNum; i++)
			{
				_playList.push_back(i);
			}
			for (int i = _frameNum - 1; i > 0; i--)
			{
				_playList.push_back(i);
			}
		}
		else
		{
			for (int i = 0; i < _frameNum; i++)
			{
				_playList.push_back(i);
			}
			for (int i = _frameNum - 1; i >= 0; i--)
			{
				_playList.push_back(i);
			}
		}
	}
	else
	{
		for (int i = 0; i < _frameNum; i++)
		{
			_playList.push_back(i);
		}
	}

}

void animation::setPlayFrame(int* playArr, int arrLen, bool loop)
{
	_loop = loop;
	_playList.clear();

	for (int i = 0; i < arrLen; i++)
	{
		_playList.push_back(playArr[i]);
	}
}

void animation::setPlayFrame(int start, int end, bool reverse, bool loop)
{
	_endPlayIndex = end;
	_loop = loop;
	_playList.clear();

	//½ÃÀÛ°ú ³¡ÀÌ °°Àº°æ¿ì(ÇÁ·¹ÀÓ±¸°£) Àç»ý ÇÏÁö ¸»ÀÚ
	if (start == end)
	{
		_playList.clear();
		stop();
		return;
	}

	else if (start > end)
	{

		if (reverse)
		{
			if (_loop)
			{

				for (int i = start; i >= end; i--)
				{
					_playList.push_back(i);
				}

				for (int i = end + 1; i < start; i++)
				{
					_playList.push_back(i);
				}
			}

			else
			{
				for (int i = start; i >= end; i--)
				{
					_playList.push_back(i);
				}

				for (int i = end + 1; i <= start; i++)
				{
					_playList.push_back(i);
				}
			}
		}
		else
		{
			for (int i = start; i <= end; i--)
			{
				_playList.push_back(i);
			}
		}
	}

	else
	{
		if (reverse)
		{
			if (_loop)
			{
				for (int i = start; i <= end; i++)
				{
					_playList.push_back(i);
				}
				for (int i = end - 1; i > start; i--)
				{
					_playList.push_back(i);
				}
			}
			else
			{
				for (int i = start; i <= end; i++)
				{
					_playList.push_back(i);
				}

				for (int i = end - 1; i <= start; i--)
				{
					_playList.push_back(i);
				}
			}
		}
		else
		{

			for (int i = start; i <= end; i++)
			{
				_playList.push_back(i);
			}
		}
	}
}

void animation::setFPS(int framePerSec)
{
	_frameUpdateSec = 1.0f / framePerSec;
}

void animation::frameUpdate(float elapsedTime)
{
	if (_play)
	{
		_elapseSec += elapsedTime;

		if (_elapseSec >= _frameUpdateSec)
		{
			_elapseSec -= _frameUpdateSec;
			_nowPlayIndex++;

<<<<<<< HEAD
=======
			if (useEventWhenSpcificFrame)
			{
				if (specificFrameIndex == _nowPlayIndex)
				{
					m_triggerWhenSpecificFrame();
				}
			}


>>>>>>> parent of 35abb8d (ëª¬ìŠ¤í„° ìµœì¢…)
			if (_nowPlayIndex == _playList.size())
			{
				if (_loop)
				{
					_nowPlayIndex = 0;
				}
				else
				{
					_nowPlayIndex--;
					_play = false;
				}
			}
		}
	}
}

void animation::start()
{
	_play = true;
	_nowPlayIndex = 0;
}

void animation::stop()
{
	_play = false;
	_nowPlayIndex = 0;
}

void animation::pause()
{
	_play = false;
}

void animation::resume()
{
	_play = true;
}

