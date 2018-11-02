#pragma once
#include"cocos2d.h"
#include "public_mercenary.h"
#include "MainGame.h"
using namespace cocos2d;
USING_NS_CC;
class Fountain :public public_mercenary{
public:
	Fountain(int side);
	~Fountain();
	CCSpriteFrameCache *m_frameCache;//����
	int type_id;//��������
	bool is_melee()override;//�Ƿ�Ϊ��ս��λ
	bool is_melee_unit;//�������
	bool IsRunning;//�ж��Ƿ����ܶ���
	bool SpriteDirecton;//�˶��ķ���
	bool skill_J_ishurted = false;
	bool skill_K_ishurted = false;
	float speed;//�ƶ��ٶ�
	float ox;//ԭʼx����
	int farthest_distance;//��Զ���
	float flew_distance = 0;//���о���ͳ��
	int life;//Ѫ��
	int orginal_life;//ԭʼѪ��
	int side;//����
	int damage_of_A;//ƽA�˺�
	bool isblowup = false;//�Ƿ񱻻���
	bool ani_block = false;//��������
	void StopAnimation();//ֹͣ���ж���
	void attack_ani();//��������
	bool hittest_A = false;//ƽA��ײ�ж�
	int attack_A_distance;//ƽA����
	void deadth_ani();//��������
	bool isdeath = false;//�Ƿ�����
	void setisOver();//���ÿ����Ƴ�


	//AI
	void core();//AI��������
	bool isOver = false;//�ɷ��Ƴ��˵�λ
	bool canControl = true;//�ɷ����
	void object_select(Vector<AllSprites *> sprites)override;//�ж�����Ŀ��
	void move();//��Ŀ���ƶ�
	void auto_Over();//�Զ�����

	int get_typeid();//��ȡ��������
	void SetAnimation(int from, int to, bool run_directon, int loop)override;//���ö���
	bool get_skill_J_ishurted()override;
	void set_skill_J_ishurted(bool skill_J_ishurted)override;
	bool get_skill_K_ishurted()override;
	void set_skill_K_ishurted(bool skill_K_ishurted)override;
	int get_life()override;//��ȡ����ֵ
	void set_life(int delta)override;//��������ֵ
	void set_life_bar(int side)override;//����Ѫ��
	bool get_hittest_A()override;
	void set_hittest_A(bool hittest_A)override;
	bool get_Direction()override;//��ȡ��ӷ���
	bool get_isblowup()override;//�Ƿ񱻻���
	void set_isblowup(bool isblowup)override;//�����Ƿ񱻻���
	bool get_canControl()override;//��ȡ�Ƿ�ɿ�
	void set_canControl(bool canControl)override;//�����Ƿ�ɿ�
	bool get_isOver()override;//��ȡ�Ƿ���Ҫ�Ƴ�
	bool get_isdeath()override;//��ȡ�Ƿ�����
	void attack_A_effect(AllSprites *enemy);//��ѪЧ��
	int get_attack_A_distance()override;//ƽA����
	void blood_effect(Sprite *sprite);//��ѪЧ��
	void removeself(Node *pSender);//�Ӹ����Ƴ�
	Sprite *get_n_Sprite();//����ڲ�����
private:
	Sprite *m_Sprite;//����
	Sprite *n_Sprite;//���飬���ɾ������
	char *sprite_name;//���������ʼ״̬�ľ���ͼƬ����
	Sprite *life_bar_fore;//Ѫ��ǰ��
	Sprite *life_bar_back;//Ѫ������
};