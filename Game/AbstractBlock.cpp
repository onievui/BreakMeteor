#include "AbstractBlock.h"


/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="_pos">���W</param>
/// <param name="_width">����</param>
/// <param name="_height">�c��</param>
/// <param name="_hp">�ϋv��</param>
/// <param name="_score">�X�R�A</param>
AbstractBlock::AbstractBlock(const Vector2 &_pos, const float _width, const float _height, const int _hp, const int _score)
	: pos(_pos)
	, vel(Vector2(0, 0))
	, angle(0)
	, width(_width)
	, height(_height)
	, hp(_hp)
	, score(_score) 
	, isValid(true) {
}

/// <summary>
///	�����蔻��̎擾
/// </summary>
/// <returns>
/// �����蔻��̃|�C���^
/// </returns>
RectRotateCollider* AbstractBlock::getCollider() const {
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
