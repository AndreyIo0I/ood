#pragma once
#include <string>
#include <filesystem>
#include "IImage.h"

class CImage : public IImage
{
public:

	CImage(const std::filesystem::path& path, int width, int height);

	// Возвращает путь относительно каталога документа
	std::filesystem::path GetPath() const override;

	// Ширина изображения в пикселях
	int GetWidth() const override;
	// Высота изображения в пикселях
	int GetHeight() const override;

	// Изменяет размер изображения
	void Resize(int width, int height) override;

	~CImage();

private:
	int m_width;
	int m_height;
	std::filesystem::path m_path;
};