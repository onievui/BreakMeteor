//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameLibInput.cpp
//!
//! @brief  ���͊֘A�̋@�\�̃\�[�X�t�@�C��
//!
//! @date   2018/10/20
//!
//! @author S.Takaki
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include "GameLibInput.h"

#include <DxLib.h>




// <InputDevice�N���X> *********************************************************

// �����o�֐��̒�` ========================================================
//----------------------------------------------------------------------
//! @brief �f�t�H���g�R���X�g���N�^
//!
//! @param[in] �Ȃ�
//----------------------------------------------------------------------
InputDevice::InputDevice()
	: m_current_state(0)
	, m_last_state(0)
{
}



//----------------------------------------------------------------------
//! @brief �f�X�g���N�^
//----------------------------------------------------------------------
InputDevice::~InputDevice()
{
}



//----------------------------------------------------------------------
//! @brief �w�肳�ꂽ�{�^����������Ă��邩�ǂ����𔻒f
//!
//! @param[in] button ���肵�����{�^���̓��̓}�X�N
//!
//! @retval true  �w�肳�ꂽ�{�^����������Ă���ꍇ
//! @retval false ����ȊO�̏ꍇ
//----------------------------------------------------------------------
bool InputDevice::IsButtonDown(int button)
{
	if ((m_current_state & button) == button)
	{
		return true;
	}
	else
	{
		return false;
	}
}



//----------------------------------------------------------------------
//! @brief �w�肳�ꂽ�{�^����������Ă��Ȃ����ǂ����𔻒f
//!
//! @param[in] button ���肵�����{�^���̓��̓}�X�N
//!
//! @retval true  �w�肳�ꂽ�{�^����������Ă��Ȃ��ꍇ
//! @retval false ����ȊO�̏ꍇ
//----------------------------------------------------------------------
bool InputDevice::IsButtonUp(int button)
{
	if ((m_current_state & button) != button)
	{
		return true;
	}
	else
	{
		return false;
	}
}



//----------------------------------------------------------------------
//! @brief �w�肳�ꂽ�{�^���������ꂽ���ǂ����𔻒f
//!
//! @param[in] button ���肵�����{�^���̓��̓}�X�N
//!
//! @retval true  �w�肳�ꂽ�L�[�������ꂽ�ꍇ
//! @retval false ����ȊO�̏ꍇ
//----------------------------------------------------------------------
bool InputDevice::IsButtonPressed(int button)
{
	if (((~m_last_state & m_current_state) & button) == button)
	{
		return true;
	}
	else
	{
		return false;
	}
}



//----------------------------------------------------------------------
//! @brief �w�肳�ꂽ�{�^���������ꂽ���ǂ����𔻒f
//!
//! @param[in] button ���肵�����{�^���̓��̓}�X�N
//!
//! @retval true  �w�肳�ꂽ�L�[�������ꂽ�ꍇ
//! @retval false ����ȊO�̏ꍇ
//----------------------------------------------------------------------
bool InputDevice::IsButtonReleased(int button)
{
	if (((m_last_state & ~m_current_state) & button) == button)
	{
		return true;
	}
	else
	{
		return false;
	}
}



// <Joypad�N���X> **************************************************************

// �����o�֐��̒�` ========================================================
//----------------------------------------------------------------------
//! @brief �f�t�H���g�R���X�g���N�^
//!
//! @param[in] �Ȃ�
//----------------------------------------------------------------------
Joypad::Joypad(int pad_id)
	: InputDevice()
	, m_id(pad_id)
{
}



//----------------------------------------------------------------------
//! @brief �f�X�g���N�^
//----------------------------------------------------------------------
Joypad::~Joypad()
{
}




//----------------------------------------------------------------------
//! @brief �W���C�p�b�h�̓��͏�Ԃ̍X�V����
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Joypad::Update(void)
{
	// ��Ԃ̗�����ۑ�
	m_last_state = m_current_state;


	// �Q�[���p�b�h�̏�Ԃ��X�V
	m_current_state = GetJoypadInputState(m_id);
}




// <Mouse�N���X> ***************************************************************

// �����o�֐��̒�` ========================================================
//----------------------------------------------------------------------
//! @brief �f�t�H���g�R���X�g���N�^
//!
//! @param[in] �Ȃ�
//----------------------------------------------------------------------
Mouse::Mouse()
	: InputDevice()
	, m_position(Point2D{0.0f, 0.0f})
{
}



//----------------------------------------------------------------------
//! @brief �f�X�g���N�^
//----------------------------------------------------------------------
Mouse::~Mouse()
{
}



//------------------------------------------------------------------
//! @brief �}�E�X�̓��͏�Ԃ̍X�V����
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//------------------------------------------------------------------
void Mouse::Update()
{
	// ��Ԃ̗�����ۑ�
	m_last_state = m_current_state;


	// �}�E�X�̏�Ԃ��X�V
	m_current_state = GetMouseInput();


	// �}�E�X�̍��W���X�V
	int pos_x, pos_y;
	GetMousePoint(&pos_x, &pos_y);

	m_position.x = static_cast<float>(pos_x);
	m_position.y = static_cast<float>(pos_y);
}



//------------------------------------------------------------------
//! @brief �}�E�X�̍��W�̎擾
//!
//! @param[in] �Ȃ�
//!
//! @return �}�E�X�̍��W
//------------------------------------------------------------------
const Point2D& Mouse::GetPosition()
{
	return m_position;
}