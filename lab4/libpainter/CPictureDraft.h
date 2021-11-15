#pragma once

#include <memory>
#include <vector>
#include "CShape.h"


class CPictureDraft
{
public:
	CPictureDraft() = default;

	bool IsEmpty() const;

	void AddShape(std::unique_ptr<CShape>&& shape);
	CShape& GetShape(int index) const;
	int GetShapeCount() const;

	CPictureDraft(CPictureDraft&&) = default;
	CPictureDraft& operator=(CPictureDraft&&) = default;

	CPictureDraft(const CPictureDraft&) = delete;
	CPictureDraft& operator=(const CPictureDraft&) = delete;

private:
	std::vector<std::unique_ptr<CShape>> m_shapes;
};
