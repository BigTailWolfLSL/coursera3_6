//#pragma warning(disable:4996)
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <vector>
#define RED 0
#define BLUE 1
#define DRAGON 0
#define NINJA 1
#define ICEMAN 2
#define LION 3
#define WOLF 4
#define SWORD 0
#define BOMB 1
#define ARROW 2
#define NEUTRAL -1
using namespace std;
int K, R, N;
int headquarter[2], atk[5], init_hp[5], num[2][5];					//五种武士的攻击力															//箭的攻击力
const string warrior[5] = { "dragon", "ninja", "iceman", "lion", "wolf" };
const string camp[2] = { "red", "blue" };
const string weapon[3] = { "sword", "bomb", "arrow" };
const int seq[2][5] = { { 2,3,4,1,0 },{ 3,0,1,2,4 } };
class Weapon {
private:
    int type;
    int r;															//武器的攻击力
    int Durability;													//弓箭的耐久度
public:
    Weapon(int type_, int Atk) :
            type(type_) {
        switch (type) {
            case SWORD:
                r = int(Atk*0.2);
                break;
            case ARROW:
                Durability = 3;
                r = R;
                break;
        }
    };
    Weapon(int k) {
        type = k;
    }
    Weapon() {};
    int getType() {
        return type;
    };
    int getR() {
        return r;
    }
    int getDurability() {
        return Durability;
    }
    void fightSword() {
        r = int(0.8 * r);
    }
    void fightArrow() {
        Durability -= 1;
    }
    Weapon &operator = (Weapon other) {
        this->r = other.getR();
        this->type = other.getType();
        this->Durability = other.getDurability();
        return *this;
    }
    bool isNULL() {
        if (type == -1)
            return true;
        else
            return false;
    }
};
const Weapon null(-1);
class Warrior {
private:
    int name;														//0-4依次为dragon, ninja, iceman, lion, wolf
    int color;														//红色代表0， 蓝色代表
    int ID;															//武士在阵营中的编号
    int hp;															//武士的生命力
    int Loyalty;													//武士的忠诚（只有lion有用）
    int city;														//武士所在城市的编号
    int Atk;														//武士的攻击力
    int direction;													//武士前进的方向，红色为1，蓝色为-1
    int step;														//已经走的步数（只有iceman有用）
    double morale;													//武士的士气（只有dragon有用）
    void Call(int DATE) {
        printf("%03d:00 %s %s %d born\n",
               DATE, camp[color].c_str(), warrior[name].c_str(), ID);
    }
    void Dragon(int energe) {
        Weapon w1(ID % 3, Atk);
        wea.at(ID % 3) = w1;
        morale = (energe - hp)*1.0 / hp;
        printf("Its morale is %.2f\n", morale);
    };
    void Ninja() {
        Weapon w1(ID % 3, Atk);
        wea.at(ID % 3) = w1;
        Weapon w2((ID + 1) % 3, Atk);
        wea.at((ID + 1) % 3) = w2;
    }
    void Iceman() {
        Weapon w1(ID % 3, Atk);
        wea.at(ID % 3) = w1;
    };
    void Lion(int energe) {
        Loyalty = energe - hp;
        printf("Its loyalty is %d\n",
               Loyalty);
    };
    void Wolf() {
        return;
    };
    void killed(int DATE, bool what) {
        if (!what)
            return;
        printf("%03d:40 %s %s %d was killed in city %d\n",
               DATE, camp[color].c_str(), warrior[name].c_str(), ID, city);
    }
    void getWeapon(Warrior* opponent) {
        if (name != WOLF)
            return;
        for (int i = 0; i < 3; i++) {
            if (wea.at(i).isNULL() && !opponent->wea.at(i).isNULL())
                wea.at(i) = opponent->wea.at(i);
        }
    }
    void superIceman() {
        if (name != ICEMAN)
            return;
        if ((step % 2) == 0) {
            if (hp > 9)
                hp -= 9;
            else
                hp = 1;
            Atk += 20;
        }
    }
    void yell(int DATE) {
        if (name != DRAGON)
            return;
        printf("%03d:40 %s dragon %d yelled in city %d\n",
               DATE, camp[color].c_str(), ID, city);
    }
public:
    bool kill;														//本回合是否杀敌
    bool live;														//是否还或者
    vector<Weapon> wea;												//指向武器的指针
    Warrior(int name_, int color_, int ID_, int hp_, int DATE, int energe) :
            name(name_), color(color_), ID(ID_), hp(hp_) {
        live = true;
        if (color == RED) {
            direction = 1;
            city = 0;
        }
        else {
            direction = -1;
            city = N + 1;
        }
        step = 0;
        Atk = atk[name];
        num[color][name]++;
        wea.push_back(null);
        wea.push_back(null);
        wea.push_back(null);
        Call(DATE);
        switch (name) {
            case DRAGON:
                Dragon(energe);
                break;
            case NINJA:
                Ninja();
                break;
            case ICEMAN:
                Iceman();
                break;
            case LION:
                Lion(energe);
                break;
            case WOLF:
                Wolf();
                break;
        }
        if (wea.at(SWORD).getR() == 0)
            wea.at(SWORD) = null;
    };
    Warrior(int k) {
        name = -1;
        wea.push_back(null);
        wea.push_back(null);
        wea.push_back(null);
    }
    Warrior() {
        wea.push_back(null);
        wea.push_back(null);
        wea.push_back(null);
    }
    int getAtk() {
        return Atk;
    }
    int getID() {
        return ID;
    }
    int getColor() {
        return color;
    }
    int getName() {
        return name;
    }
    int getCity() {
        return city;
    }
    int getHp() {
        return hp;
    }
    int getLoyalty() {
        return Loyalty;
    }
    int getDirection() {
        return direction;
    }
    int getStep() {
        return step;
    }
    double getMorale() {
        return morale;
    }
    bool isLive() {
        return live;
    }
    Warrior &operator = (Warrior other) {
        if (other.isNULL()) {
            this->name = other.getName();
            return *this;
        }
        this->name = other.getName();
        this->color = other.getColor();
        this->ID = other.getID();
        this->Atk = other.getAtk();
        this->city = other.getCity();
        this->hp = other.getHp();
        this->direction = other.getDirection();
        this->step = other.getStep();
        this->wea.at(0) = other.wea.at(0);
        this->wea.at(1) = other.wea.at(1);
        this->wea.at(2) = other.wea.at(2);
        this->morale = other.getMorale();
        this->Loyalty = other.getLoyalty();
        this->live = other.live;
        this->kill = other.kill;
        return *this;
    }
    void attack(Warrior* opponent, int DATE, bool what) {
        if (what) {
            printf("%03d:40 %s %s %d attacked %s %s %d in city %d with %d elements and force %d\n",
                   DATE, camp[color].c_str(), warrior[name].c_str(), ID,
                   camp[opponent->getColor()].c_str(), warrior[opponent->getName()].c_str(), opponent->getID(),
                   city, hp, Atk);
        }
        int at = Atk;
        int HP = opponent->getHp();
        if (!wea.at(SWORD).isNULL()) {
            at += wea.at(SWORD).getR();
            wea.at(SWORD).fightSword();
            if (wea.at(SWORD).getR() == 0)
                wea.at(SWORD) = null;
        }
        kill = opponent->Injured(at, DATE, what);
        if (!kill)
            opponent->CounterAttack(this, DATE, what);
        if (!isLive())
            return;
        if (kill && opponent->getName() == LION)
            hp += HP;
    };
    void CounterAttack(Warrior* opponent, int DATE, bool what) {
        if (name == NINJA)
            return;
        int HP = opponent->getHp();
        int at = Atk / 2;
        if (!wea.at(SWORD).isNULL()) {
            at += wea.at(SWORD).getR();
            wea.at(SWORD).fightSword();
            if (wea.at(SWORD).getR() == 0)
                wea.at(SWORD) = null;
        }
        if(what)
            printf("%03d:40 %s %s %d fought back against %s %s %d in city %d\n",
                   DATE, camp[color].c_str(), warrior[name].c_str(), ID,
                   camp[opponent->getColor()].c_str(), warrior[opponent->getName()].c_str(), opponent->getID(),
                   city);
        kill = opponent->Injured(at, DATE, what);
        if (kill && opponent->getName() == LION)
            hp += HP;
    }
    bool Injured(int injured, int DATE, bool what) {
        hp -= injured;
        if (hp <= 0) {
            live = false;
            killed(DATE, what);
            return true;
        }
        return false;
    }
    bool shoted(int injured) {
        hp -= injured;
        if (hp <= 0) {
            live = false;
            return true;
        }
        return false;
    }
    void March() {
        if (city + direction >= 0 && city + direction <= N + 1) {
            city += direction;
            step++;
            superIceman();
        }
    }
    bool marchClaim(int DATE) {
        if (color == RED && city == N + 1) {
            printf("%03d:10 red %s %d reached blue headquarter with %d elements and force %d\n",
                   DATE, warrior[name].c_str(), ID, hp, Atk);
            return true;
        }
        else if (color == BLUE && city == 0) {
            printf("%03d:10 blue %s %d reached red headquarter with %d elements and force %d\n",
                   DATE, warrior[name].c_str(), ID, hp, Atk);
            return true;
        }
        else {
            printf("%03d:10 %s %s %d marched to city %d with %d elements and force %d\n",
                   DATE, camp[color].c_str(), warrior[name].c_str(), ID, city, hp, Atk);
            return false;
        }
    }
    void shot(int DATE, Warrior* opponent) {
        bool kill = opponent->shoted(R);
        wea.at(ARROW).fightArrow();
        if (wea.at(ARROW).getDurability() == 0)
            wea.at(ARROW) = null;
        printf("%03d:35 %s %s %d shot",
               DATE, camp[color].c_str(), warrior[name].c_str(), ID);
        if (kill)
            printf(" and killed %s %s %d\n",
                   camp[opponent->getColor()].c_str(), warrior[opponent->getName()].c_str(), opponent->getID());
        else
            printf("\n");
    }
    void useBomb(int DATE, Warrior* opponent) {
        if (wea[BOMB].isNULL())
            return;
        else {
            live = false;
            opponent->live = false;
            printf("%03d:38 %s %s %d used a bomb and killed %s %s %d\n",
                   DATE, camp[color].c_str(), warrior[name].c_str(), ID,
                   camp[opponent->getColor()].c_str(), warrior[opponent->getName()].c_str(), opponent->getID());
        }
    }
    void earn(int DATE, int elements) {
        hp += elements;
        printf("%03d:40 %s %s %d earned %d elements for his headquarter\n",
               DATE, camp[color].c_str(), warrior[name].c_str(), ID, elements);
    }
    void report(int DATE) {
        string hasWeapon[3];
        int cnt = 0;
        if (!wea.at(ARROW).isNULL()) {
            cnt++;
            char buf[64];
            sprintf(buf, "arrow(%d)", wea.at(ARROW).getDurability());
            hasWeapon[0] = buf;
        }
        if (!wea.at(BOMB).isNULL()) {
            cnt++;
            hasWeapon[1] = "bomb";
        }
        if (!wea.at(SWORD).isNULL()) {
            cnt++;
            char buf[64];
            sprintf(buf, "sword(%d)", wea.at(SWORD).getR());
            hasWeapon[2] = buf;
        }
        printf("%03d:55 %s %s %d has ",
               DATE, camp[color].c_str(), warrior[name].c_str(), ID);
        int countOut = 0;
        for (int i = 0; i < 3; i++) {
            printf("%s", hasWeapon[i].c_str());
            if (hasWeapon[i] != "" && countOut != cnt - 1) {
                countOut++;
                printf(",");
            }
        }
        if (cnt == 0)
            printf("no weapon");
        printf("\n");
    }
    bool runAway(int DATE) {
        if (name != LION)
            return false;
        if (Loyalty <= 0) {
            printf("%03d:05 %s lion %d ran away\n",
                   DATE, camp[color].c_str(), ID);
            return true;
        }
        return false;
    }
    bool isNULL() {
        if (name == -1)
            return true;
        else
            return false;
    }
    void reward() {
        hp += 8;
    }
    void afterFight(int DATE, Warrior* opponent, int pre) {
        if (name == LION) {
            if (!kill)
                Loyalty -= K;
        }
        else if (name == DRAGON) {
            if (kill)
                morale += 0.2;
            else
                morale -= 0.2;
            if (live && morale > 0.8 && pre == color)
                yell(DATE);
        }
        else if (name == WOLF && kill) {
            getWeapon(opponent);
        }
    }

};
const Warrior Wnull(-1);
class City {
private:
    int Flag;
    int num;
    int element;
    int Win[2];
public:
    City* nextCity;
    City* lastCity;
    Warrior intruder;												//入侵者，只有两个司令部的入侵者可能不为Wnull
    Warrior warrior_red;
    Warrior warrior_r_t;
    Warrior warrior_blue;
    Warrior warrior_b_t;
    City() {};
    City(int num_) :
            num(num_) {
        element = 0;
        Flag = NEUTRAL;												//初始为中立
        Win[0] = NEUTRAL;
        Win[1] = NEUTRAL;
        intruder = Wnull;
        warrior_red = Wnull;
        warrior_blue = Wnull;
        warrior_r_t = Wnull;
        warrior_b_t = Wnull;
        nextCity = NULL;
        lastCity = NULL;
    };
    void Trans(int DATE) {											//要转换旗帜只有连续两次战斗有胜方且相同
        if ((Win[0] == Win[1]) &&									//上次和上上次战斗的结果相同
            Win[0] != NEUTRAL &&									//上上次战斗的结果不为平手
            Win[1] != NEUTRAL &&									//上次战斗的结果不为平手
            Win[0] != Flag) {										//如果胜方等于旗帜的颜色则不需要转换
            Flag = Win[0];
            printf("%03d:40 %s flag raised in city %d\n",			//flag立起来
                   DATE, camp[Flag].c_str(), num);
        }
    }
    int getFlag() {
        return Flag;
    }
    int getNum() {
        return num;
    }
    void product() {
        element += 10;
    }
    void clear() {
        element = 0;
    }
    int getColor() {
        if ((Flag == RED) || ((Flag == NEUTRAL) && ((num % 2) == 1)))
            return RED;
        else
            return BLUE;
    }
    int getElement() {
        return element;
    }
    void March_r_step1() {
        if (!warrior_red .isNULL() && nextCity != NULL) {
            warrior_red.March();
            nextCity->warrior_r_t = warrior_red;
            warrior_red = Wnull;
        }
    }
    void March_b_step1() {
        if (!warrior_blue.isNULL() && lastCity != NULL) {
            warrior_blue.March();
            lastCity->warrior_b_t = warrior_blue;
            warrior_blue = Wnull;
        }
    }
    bool March_r_step2(int DATE) {
        bool flag = false;
        if (!warrior_r_t.isNULL()) {
            flag = warrior_r_t.marchClaim(DATE);
            warrior_red = warrior_r_t;
            warrior_r_t = Wnull;
        }
        return flag;
    }
    bool March_b_step2(int DATE) {
        bool flag = false;
        if (!warrior_b_t.isNULL()) {
            flag = warrior_b_t.marchClaim(DATE);
            warrior_blue = warrior_b_t;
            warrior_b_t = Wnull;
        }
        return flag;
    }
    int fight(int DATE) {
        int winner = NEUTRAL;
        if (!warrior_red.isNULL() && !warrior_blue.isNULL()) {		//发动战斗首先要求有两个武士，结果则是一死一活或者两活
            if (getColor() == RED) {								//红方先手，并且红武士还活着则进攻
                if (warrior_red.isLive()) {							//红武士还活着
                    if (!warrior_blue.isLive()) {					//如果对方是被射死的
                        warrior_red.kill = true;					//仍然判定本回合杀敌
                        warrior_red.afterFight(DATE, &warrior_blue, RED);
                    }
                    else {
                        warrior_red.attack(&warrior_blue, DATE, true);
                        if (warrior_red.isLive())
                            warrior_red.afterFight(DATE, &warrior_blue, RED);	//只要活着就能做战后动作
                        if (warrior_blue.isLive())
                            warrior_blue.afterFight(DATE, &warrior_red, RED);	//只要活着就能做战后动作
                    }
                }
                else {												//红武士死了，如果蓝武士还活着直接判定蓝武士胜利
                    if (warrior_blue.isLive()) {
                        warrior_blue.kill = true;
                        warrior_blue.afterFight(DATE, &warrior_red, RED);
                    }
                }
            }
            else if (getColor() == BLUE) {							//蓝方先手，并且蓝武士还活着则进攻
                if (warrior_blue.isLive()) {						//蓝武士还活着
                    if (!warrior_red.isLive()) {					//如果对方是被射死的
                        warrior_blue.kill = true;					//仍然判定本回合杀敌
                        warrior_blue.afterFight(DATE, &warrior_red, BLUE);
                    }
                    else {
                        warrior_blue.attack(&warrior_red, DATE, true);
                        if (warrior_red.isLive())
                            warrior_red.afterFight(DATE, &warrior_blue, BLUE);	//只要活着就能做战后动作
                        if (warrior_blue.isLive())
                            warrior_blue.afterFight(DATE, &warrior_red, BLUE);	//只要活着就能做战后动作
                    }
                }
                else {												//蓝武士死了，如果红武士还活着则判定蓝武士胜利
                    if (warrior_red.isLive()) {
                        warrior_red.kill = true;
                        warrior_red.afterFight(DATE, &warrior_blue, BLUE);
                    }
                }
            }
            if (!warrior_red.isLive() && warrior_blue.isLive()) {	//红死蓝活
                warrior_red = Wnull;
                Win[0] = Win[1];
                Win[1] = BLUE;
                winner = BLUE;
            }
            else if (!warrior_blue.isLive() && warrior_red.isLive()) {	//蓝死红活
                warrior_blue = Wnull;
                Win[0] = Win[1];
                Win[1] = RED;
                winner = RED;
            }
            else if (!warrior_blue.isLive() && !warrior_red.isLive()) {
                warrior_red = Wnull;
                warrior_blue = Wnull;
            }
            else {								//两个都活，则连胜中断
                Win[0] = Win[1];
                Win[1] = NEUTRAL;
            }
        }
        /*如果返回NEUTRAL,则有两种情况
        **一.没有开战，由本函数可知没有开战虽然返回的是NEUTRAL，但是
        **最近两次的战斗结果是不变的
        **二.开战了，无人死亡，则战斗结果为中立
        **三.没有开战且全部死亡，则战斗结果不变
        */
        return winner;
    }
    void boom(int DATE) {
        if (!warrior_red.isNULL() && !warrior_blue.isNULL() && warrior_red.isLive() && warrior_blue.isLive()) {
            //如果敌人或者自己有一个是已经死去的则不考虑bomb
            if (getColor() == RED) {
                Warrior warrior1 = warrior_red;						//复制红武士
                Warrior warrior2 = warrior_blue;					//复制蓝武士
                warrior1.attack(&warrior2, DATE, false);			//发动攻击
                if (!warrior1.isLive())								//如果正常攻击之后红武士死去，则红武士考虑bomb
                    warrior_red.useBomb(DATE, &warrior_blue);
                if (!warrior2.isLive())								//如果正常攻击之后蓝武士死去，则蓝武士考虑bomb
                    warrior_blue.useBomb(DATE, &warrior_red);
            }
            else {
                Warrior warrior1 = warrior_red;
                Warrior warrior2 = warrior_blue;
                warrior2.attack(&warrior1, DATE, false);
                if (!warrior1.isLive())
                    warrior_red.useBomb(DATE, &warrior_blue);
                if (!warrior2.isLive())
                    warrior_blue.useBomb(DATE, &warrior_red);
            }
            if (!warrior_red.isLive() && !warrior_blue.isLive()) {	//如果考虑bomb之后两者都死去，则是被炸死的，赋值Wnull
                warrior_red = Wnull;
                warrior_blue = Wnull;
            }
        }
    }
    void win(int winner) {
        Win[0] = Win[1];
        Win[1] = winner;
    }
};
class Camp {
private:
    int energe;														//拥有的生命元数目
    int last;														//上一次制造的士兵阵营编号
    int warriorNum;													//已有武士数目+1
    int color;														//阵营颜色
    int headQuarter;												//司令部所在的城市编号
    vector<Warrior> Warr;
    void getWarrior(int I, int DATE, int &last, vector<City> &Map) {
        int name = seq[color][I];
        int hp = init_hp[name];
        Warrior warri = Warrior(name, color, warriorNum, hp, DATE, energe);
        Warr.push_back(warri);
        if (color == RED)
            Map[headQuarter].warrior_red = Warr.back();
        else
            Map[headQuarter].warrior_blue = Warr.back();
        energe -= hp;
        last = I;
        warriorNum++;
        return;
    }

public:
    int intruder;
    Camp(int energe_, int color_) :
            energe(energe_), color(color_) {
        last = -1;
        warriorNum = 1;
        intruder = 0;
        if (color == RED)
            headQuarter = 0;
        else
            headQuarter = N + 1;
    }
    ~Camp() {}
    void Build(int DATE, vector<City> &Map) {
        int I = (last + 1) % 5;
        if (energe >= init_hp[seq[color][I]]) {
            getWarrior(I, DATE, last, Map);
            return;
        }
    }
    int getEnerge() {
        return energe;
    }
    int getColor() {
        return color;
    }
    void claim(int DATE) {
        printf("%03d:50 %d elements in %s headquarter\n",
               DATE, energe, camp[color].c_str());
    }
    void getElement(int ele) {
        energe += ele;
    }
    void reward() {
        energe -= 8;
    }
};
class War {
private:
    int M, T;
    bool over;
    bool flag[2];
    vector<City> Map;
    vector<Camp>headQuarter;
    void Input() {
        cin >> M >> N >> R >> K >> T;
        for (int i = 0; i < 5; i++)
            cin >> init_hp[i];
        for (int i = 0; i < 5; i++)
            cin >> atk[i];
    }
    void Init(int &k) {
        memset(num, 0, sizeof(num));
        over = false;
        for (int i = 0; i <= N + 1; i++) {
            Map.push_back(City(i));
        }
        for (int i = 0; i <= N + 1; i++) {
            if (i == 0)
                Map.at(i).lastCity = NULL;
            else
                Map.at(i).lastCity = &Map[i - 1];
            if (i == N + 1)
                Map.at(i).nextCity = NULL;
            else
                Map.at(i).nextCity = &Map[i + 1];
        }
        printf("Case %d:\n", k++);
    }
    void runAway(int DATE){
        City* city = &Map[0];
        while (city != NULL) {
            if (!city->warrior_red.isNULL()) {
                if(city->warrior_red.runAway(DATE))
                    city->warrior_red = Wnull;						//逃跑之后指向原来狮子的指针变回Wnull
            }
            if (!city->warrior_blue.isNULL()) {
                if(city->warrior_blue.runAway(DATE))
                    city->warrior_blue = Wnull;
            }
            city = city->nextCity;
        }
    }
    void March(int DATE){
        bool flag[2] = { false, false };
        City* city = &Map[0];
        while (city != NULL) {
            city->March_r_step1();									//先挂载
            city->March_b_step1();									//先挂载
            city = city->nextCity;
        }
        city = &Map[0];
        while (city != NULL) {
            if (city->March_r_step2(DATE)) {
                headQuarter[BLUE].intruder++;						//到达司令部
                if (headQuarter[BLUE].intruder == 2)				//两个武士到达司令部
                    printf("%03d:10 blue headquarter was taken\n", DATE);
            }
            if (city->March_b_step2(DATE)) {
                headQuarter[RED].intruder++;
                if (headQuarter[RED].intruder == 2)
                    printf("%03d:10 red headquarter was taken\n", DATE);
            }
            city = city->nextCity;
        }
        if (!Map.at(0).warrior_blue.isNULL()) {
            Map.at(0).intruder = Map.at(0).warrior_blue;
            Map.at(0).warrior_blue = Wnull;
        }
        if (!Map.at(N+1).warrior_blue.isNULL()) {
            Map.at(N + 1).intruder = Map.at(N + 1).warrior_red;
            Map.at(N + 1).warrior_red = Wnull;
        }
    }
    void productElement(){
        City* city = &Map[0];
        while (city != NULL) {
            city->product();										//生产生命元
            city = city->nextCity;
        }
    }
    void getElement(int DATE) {
        City* city = &Map[1];
        while (city->nextCity != NULL) {							//除了司令部，所有的都开始收获能量
            if (city->getElement() == 0) {							//没有就继续
                city = city->nextCity;
                continue;
            }
            Warrior &warrior1 = city->warrior_red;
            Warrior &warrior2 = city->warrior_blue;
            if (!warrior1.isNULL() && warrior2.isNULL()) {			//有红武士没有蓝武士
                headQuarter.at(RED).getElement(city->getElement());	//红司令部收获
                printf("%03d:30 red %s %d earned %d elements for his headquarter\n",
                       DATE, warrior[warrior1.getName()].c_str(), warrior1.getID(), city->getElement());
                city->clear();										//收获后清零
            }
            else if (warrior1.isNULL() && !warrior2.isNULL()) {		//有蓝武士没有红武士
                headQuarter.at(BLUE).getElement(city->getElement());//蓝司令部收获
                printf("%03d:30 blue %s %d earned %d elements for his headquarter\n",
                       DATE, warrior[warrior2.getName()].c_str(), warrior2.getID(), city->getElement());
                city->clear();										//收获后清零
            }
            city = city->nextCity;
        }
    }
    void shot(int DATE){											//射箭，每个城市开始，对将走到的下个城市的敌人放箭
        City* city = &Map[0];
        while (city != NULL) {
            if (!city->warrior_red.isNULL() &&						//有红武士
                !(city->warrior_red.wea[ARROW].isNULL()) &&			//红武士有弓箭
                (city->nextCity != NULL)) {							//这不是最后一个城市
                if (!(city->nextCity->warrior_blue.isNULL()) &&		//下一个城市有敌人
                    city->nextCity->nextCity != NULL)				//下一个城市不是司令部
                    city->warrior_red.shot(DATE, &(city->nextCity->warrior_blue));
            }
            if (!(city->warrior_blue.isNULL()) &&					//有蓝武士
                !(city->warrior_blue.wea[ARROW].isNULL()) &&		//蓝武士有弓箭
                (city->lastCity != NULL)) {							//这不是第一个城市
                if (!city->lastCity->warrior_red.isNULL() &&		//上一个城市有敌人
                    city->lastCity->lastCity != NULL)				//上一个城市不是司令部
                    city->warrior_blue.shot(DATE, &(city->lastCity->warrior_red));
            }
            city = city->nextCity;
        }
    }
    void bomb(int DATE){
        City* city = &Map[0];
        while (city != NULL) {
            city->boom(DATE);
            city = city->nextCity;
        }
    }
    void attack(int DATE){
        City* city = &Map[0];
        while (city != NULL) {
            int winner = city->fight(DATE);							//winner是战斗结果，RED,BLUE分别是红、蓝胜利，NEUTRAL是平手
            if (winner != NEUTRAL) {								//如果有胜方
                clean(DATE, city, winner);							//胜方打扫战场并奖赏
                city->Trans(DATE);									//判定是否需要转换旗帜
            }
            city = city->nextCity;
        }
        city = &Map[0];
        while (city != NULL) {										//处理那些被射死的武士
            if (!city->warrior_red.isNULL())
                if (!city->warrior_red.isLive())					//战斗后还没有被处理的尸体处理掉
                    city->warrior_red = Wnull;
            if (!city->warrior_blue.isNULL())
                if (!city->warrior_blue.isLive())
                    city->warrior_blue = Wnull;
            city = city->nextCity;
        }
    }
    void report(int DATE){
        City* city = &Map[0];
        while (city != NULL) {
            if (!city->warrior_red.isNULL())
                city->warrior_red.report(DATE);
            city = city->nextCity;
        }
        if (!Map.at(N + 1).intruder.isNULL())
            Map.at(N + 1).intruder.report(DATE);					//入侵者也要报告武器使用情况
        city = &Map[0];
        if (!Map.at(0).intruder.isNULL())
            Map.at(0).intruder.report(DATE);						//入侵者也要报告武器使用情况
        while (city != NULL) {
            if (!city->warrior_blue.isNULL())
                city->warrior_blue.report(DATE);
            city = city->nextCity;
        }
    }
    void isOver(int DATE) {											//是否满足司令部被攻破这一条件
        if (headQuarter[RED].intruder == 2)
            over = true;
        if (headQuarter[BLUE].intruder == 2)
            over = true;
    }
    void clean(int DATE, City* city, int color) {
        if (headQuarter[color].getEnerge() >= 8) {
            if (color == RED)
                city->warrior_red.reward();
            else
                city->warrior_blue.reward();
            headQuarter[color].reward();
        }
        if (city->getElement() > 0) {
            headQuarter[color].getElement(city->getElement());
            if (color == RED) {
                printf("%03d:40 red %s %d earned %d elements for his headquarter\n",
                       DATE, warrior[city->warrior_red.getName()].c_str(), city->warrior_red.getID(), city->getElement());
                city->warrior_red.kill = false;
            }
            else {
                printf("%03d:40 blue %s %d earned %d elements for his headquarter\n",
                       DATE, warrior[city->warrior_blue.getName()].c_str(), city->warrior_blue.getID(), city->getElement());
                city->warrior_blue.kill = false;
            }
            city->clear();
        }
    }
    bool ddl(int DATE, int t) {										//判定时间是否到了
        if (DATE * 60 + t > T)
            return true;
        return false;
    }
public:
    War(int &k) {
        Input();													//输入数据
        Init(k);													//进行初始化
    };

    void Fight() {
        int TIME = 0;
        headQuarter.push_back(Camp(M, RED));						//构造司令部红
        headQuarter.push_back(Camp(M, BLUE));						//构造司令部蓝
        while (!over) {
            if (ddl(TIME, 0))
                break;
            headQuarter[RED].Build(TIME, Map);						//00司令部制造
            headQuarter[BLUE].Build(TIME, Map);						//00司令部制造
            if (ddl(TIME, 5))
                break;
            runAway(TIME);											//05狮子逃跑
            if (ddl(TIME, 10))
                break;
            March(TIME);											//10武士前进
            isOver(TIME);
            if (over)
                break;
            if (ddl(TIME, 20))
                break;
            productElement();										//20城市产出生命元
            if (ddl(TIME, 30))
                break;
            getElement(TIME);										//30只有一个武士的城市夺走生命元
            if (ddl(TIME, 35))
                break;
            shot(TIME);												//35武士放箭
            if (ddl(TIME, 38))
                break;
            bomb(TIME);												//38放bomb
            if (ddl(TIME, 40))
                break;
            attack(TIME);											//40发生战斗
            if (ddl(TIME, 50))
                break;
            headQuarter[RED].claim(TIME);							//50司令部报告生命元
            headQuarter[BLUE].claim(TIME);							//50司令部报告生命元
            if (ddl(TIME, 55))
                break;
            report(TIME);											//55武士报告武器情况
            TIME++;
        }
    }
};
int main() {
    int t;
    cin >> t;
    int k = 1;
    while (t--) {
        War aWar(k);
        aWar.Fight();
    }
    return 0;
}