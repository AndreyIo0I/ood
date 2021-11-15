#include "CPictureDraft.h"
using namespace std;

bool CPictureDraft::IsEmpty() const
{
	return m_shapes.empty();
}

void CPictureDraft::AddShape(std::unique_ptr<CShape>&& shape)
{
	m_shapes.push_back(move(shape));
}

CShape& CPictureDraft::GetShape(int index) const
{
	return *m_shapes.at(index);
}

int CPictureDraft::GetShapeCount() const
{
	return m_shapes.size();
}
