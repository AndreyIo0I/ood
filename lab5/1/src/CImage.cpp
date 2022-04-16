#include "CImage.h"
#include <stdexcept>
#include <filesystem>

CImage::CImage(const std::filesystem::path& path, int width, int height)
    : m_width(width)
    , m_height(height)
{
    if (m_width < 1 || m_width > 10000 || m_height < 1 || m_height > 10000)
        throw std::invalid_argument("Size must be between 1 and 10000");

    if (!std::filesystem::exists(path))
        throw std::invalid_argument("File does not exist");

    std::filesystem::create_directories("images");
    m_path = "images/" + path.stem().string() + std::to_string(std::rand()) + path.extension().string();
    std::filesystem::copy_file(path, m_path, std::filesystem::copy_options::overwrite_existing);
}

std::filesystem::path CImage::GetPath() const
{
    return m_path.string();
}

int CImage::GetWidth() const
{
    return m_width;
}

int CImage::GetHeight() const
{
    return m_height;
}

void CImage::Resize(int width, int height)
{
    m_width = width;
    m_height = height;
}

CImage::~CImage()
{
    std::filesystem::remove(m_path);
}
