#pragma once
#include "Vector3.h"
#include <stdint.h>
#include <vector>

// �`���I�ȗ񋓂Ɣ�ׂ�enum class�ɂ͎��̗��_������܂��B
// enum class�̗񋓒l�͈ÖٓI�ɐ����^�ɕϊ����ꂸ�A
// �����I�Ɍ^�ϊ����w�肷��K�v������܂��B
// enum class��enum�l�͂���enum�^���ň�ӂł���A
// ���̃X�R�[�v�̎��ʎq�Ƃ͏Փ˂��܂���
enum class MapChipType {
	kBlank, // ��
	kBlock, // �u���b�N
};

struct MapChipData {
	std::vector<std::vector<MapChipType>> data;
};

/// <summary>
/// �}�b�v�`�b�v�t�B�[���h
/// </summary>
class MapChipField {
public:
	void ResetMapChipData();
	void LoadMapChipCsv(const std::string& filePath);
	MapChipType GetMapChipTypeByIndex(uint32_t xIndex, uint32_t yIndex);
	Vector3 GetMapChipPositionByIndex(uint32_t xIndex, uint32_t yIndex);
	uint32_t GetNumBlockVirtical();
	uint32_t GetNumBlockHorizontal();

private:
	// 1�u���b�N�̃T�C�Y
	static inline const float kBlockWidth = 2.0f;
	static inline const float kBlockHeight = 2.0f;
	// �u���b�N�̌�
	static inline const uint32_t kNumBlockVirtical = 20;
	static inline const uint32_t kNumBlockHorizontal = 100;

	MapChipData mapChipData_;
};
