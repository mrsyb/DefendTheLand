#pragma once
#include"cocos2d.h"
#include "public_mercenary.h"
#include "MainGame.h"
using namespace cocos2d;
USING_NS_CC;
class horseMan :public public_mercenary{
public:
	horseMan(int side);
	~horseMan();
	CCSpriteFrameCache *m_frameCache;//����
	int type_id;//��������
	bool is_melee()override;//�Ƿ�Ϊ��ս��λ
	bool is_melee_unit;//�������
	bool IsRunning;//�ж��Ƿ����ܶ���
	bool SpriteDirecton;//�˶��ķ���
	bool skill_J_ishurted = false;
	bool skill_K_ishurted = false;
	float speed;//�ƶ��ٶ�
	float orginal_speed;//ԭʼ�ٶ�
	int pay_back;//ֵ����Ǯ
	int life;//Ѫ��
	int orginal_life;//ԭʼѪ��
	int side;//Ӣ����Ӫ��0Ϊ��ɫ����1Ϊ��ɫ��
	int damage_of_A;//ƽA�˺�
	bool isblowup = false;//�Ƿ񱻻���
	float random_y = 0;//վλ�ص�����
	int walk_from;
	int walk_to;
	int attack_from;
	int attack_to;
	int die_from;
	int die_to;
	const char *name_each;//�����ļ���������
	bool ani_block = false;//��������
	void StopAnimation();//ֹͣ���ж���
	void walk(bool run_directon);//��·����
	void idle();//վ������
	void attack_ani();//��������
	void attack_A_img_end();//�չ���β
	void attack_A_end();//ֹͣ����
	bool attack_A = false;//�Ƿ���ƽA
	bool hittest_A = false;//ƽA��ײ�ж�
	int attack_A_distance;//ƽA����
	int attack_area;
	int attack_gap = 41;//�չ����
	int attack_now = 0;//���ж೤ʱ����ƶ���������̹���
	float ox = 0;//��ԭx����
	void deadth_ani();//��������
	bool isdeath = false;//�Ƿ�����
	void setisOver();//���ÿ����Ƴ�
	int earn_money()override;//ֵ����Ǯ
	bool paid = false;//�Ƿ����Ǯ
	bool isMoving = false;//�Ƿ������ƶ�

	//AI
	void core();//AI��������
	bool isOver = false;//�ɷ��Ƴ��˵�λ
	bool canControl = true;//�ɷ����
	void object_select(Vector<AllSprites *> sprites);//�ж�����Ŀ��
	AllSprites *object_aim = nullptr;//����Ŀ��
	void move();//��Ŀ���ƶ�

	int get_typeid();//��ȡ��������
	void SetAnimation(int from, int to, bool run_directon, int loop)override;//���ö���
	bool get_skill_J_ishurted()override;
	void set_skill_J_ishurted(bool skill_J_ishurted)override;
	bool get_skill_K_ishurted()override;
	void set_skill_K_ishurted(bool skill_K_ishurted)override;
	int get_life()override;//��ȡ����ֵ
	void set_life(int delta)override;//��������ֵ
	void set_life_bar(int side)override;//����Ѫ��
	float get_speed();//����ٶ�
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
	void blood_effect(AllSprites *sprite);//��ѪЧ��
	void removeself(Node *pSender);//�Ӹ����Ƴ�
	Sprite *get_n_Sprite();//����ڲ�����
	void set_money_paid(bool paid);//�����Ƿ����Ǯ
	bool get_money_paid();//��ȡ�Ƿ����Ǯ
	void set_isMoving(bool isMoving)override;//�����Ƿ������ƶ�
	bool get_isMoving()override;//����Ƿ������ƶ�
private:
	Sprite *m_Sprite;//����
	Sprite *n_Sprite;//���飬���ɾ������
	char *sprite_name;//���������ʼ״̬�ľ���ͼƬ����
	Sprite *life_bar_fore;//Ѫ��ǰ��
	Sprite *life_bar_back;//Ѫ������
};