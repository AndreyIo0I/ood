#pragma once
#include <string>
#include <filesystem>
#include "IImage.h"

class CImage : public IImage
{
public:

	CImage(const std::filesystem::path& path, int width, int height);

	// ���������� ���� ������������ �������� ���������
	std::filesystem::path GetPath() const override;

	// ������ ����������� � ��������
	int GetWidth() const override;
	// ������ ����������� � ��������
	int GetHeight() const override;

	// �������� ������ �����������
	void Resize(int width, int height) override;

	~CImage();

private:
	int m_width;
	int m_height;
	std::filesystem::path m_path;
};