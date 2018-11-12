#include "AbstractBlock.h"

/// <summary>
///	�����蔻��̎擾
/// </summary>
/// <returns>
/// �����蔻��̃|�C���^
/// </returns>
RectCollider* AbstractBlock::getCollider() const {
	return collider.get();
}

/// <summary>
/// �u���b�N�����݂��邩
/// </summary>
/// <returns>
/// true:���݂���
/// false:���݂��Ȃ�
/// </returns>
bool AbstractBlock::isDestroyed() const {
	return !isValid;
}
