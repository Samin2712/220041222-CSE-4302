#include<iostream>
#include<vector>
using namespace std;
class CharacterActions 
{
    public:
        virtual void attack()=0;
        virtual void defend()=0;
        virtual void useSpecialAbility()=0;
        virtual void displayStats() const=0;
        virtual bool isAlive() const=0;
        virtual ~CharacterActions()=default;
};
class BaseCharacter:public CharacterActions
{
    protected:
        string name;
        int health;
        int mana;
        int attpower;
        string special_ability;
        int special_ability_power;
    public:
        BaseCharacter(string n,int h,int a_power,string s_ab,int s_power):name(n),health(h),attpower(a_power),special_ability(s_ab),special_ability_power(s_power){}

        void defend() override
        {
            cout<<name<<"defends! Attack blocked."<<endl;
        }
        void displayStats() const override
        {
            cout<<"Name: "<<name<<", Health: "<<health<<", Mana: "<<mana<<endl;
        }
        virtual void takeDamage(int damage)
        {
            health-=damage;
            cout <<name<<" takes "<<damage<<" damage! Health now: "<<health<<endl;
        }
        bool isAlive() const override
        {
            return health>0;
        }
        virtual void resetMana()
        {
            mana=0;
        }
        void gainMana(int am)
        {
            mana+=am;
        }
        string getName()const
        {
            return name;
        }
        int getAttackPower() const
        {
            return attpower;
        }
        int getSpecialAbilityPower() const
        {
            return special_ability_power;
        }
        int getmana() const
        {
            return mana;
        }
};
class Warrior:public BaseCharacter
{
    public:
        Warrior():BaseCharacter("Warrior",100,25,"Berserk Rage",35) {}
        void attack() override
        {
            cout<<name<<" attacks with power "<<attpower<<"!" << endl;
            gainMana(50);
        }
        void useSpecialAbility() override
        {
            if (mana>=100)
            {
                cout<<name<<" uses "<<special_ability<<" with power "<<special_ability_power<< "!" << endl;
                resetMana();
            } 
            else
            {
                cout<<name<<" does not have enough mana to use "<<special_ability<<"!" << endl;
            }
        }
};
class Mage:public BaseCharacter
{
    public:
        Mage():BaseCharacter("Mage",120,20,"Arcane Blast",30){}
        void attack() override
        {
            cout<<name<<" attacks with power "<<attpower<<"!"<<endl;
            gainMana(50);
        }
        void useSpecialAbility() override
        {
            if (mana>=100)
            {
                cout<<name<<" uses "<<special_ability<<" with power "<<special_ability_power<<"!"<<endl;
                resetMana();
            } 
            else
            {
                cout<<name<<" does not have enough mana to use "<<special_ability<<"!"<<endl;
            }
        }
};
class Archer:public BaseCharacter
{
    public:
        Archer():BaseCharacter("Archer",90,20,"Fire Arrow",35){}
        void attack() override
        {
            cout<<name<<" attacks with power "<<attpower<<"!" << endl;
            gainMana(50);
        }
        void useSpecialAbility() override
        {
            if (mana>=100)
            {
                cout<<name<<" uses "<<special_ability<<" with power "<<special_ability_power<< "!" << endl;
                resetMana();
            } 
            else
            {
                cout<<name<<" does not have enough mana to use "<<special_ability<<"!" << endl;
            }
        }
};
class BossEnemy
{
    private:
        string name;
        int health;
        int attackPower;
    public:
        BossEnemy():name("Boss"),health(150),attackPower(30){}
        void takeDamage(int damage)
        {
            health-=damage;
            cout<<name<< " takes "<<damage<<" damage! Health now: "<<health<<endl;
        }
        void attack(BaseCharacter& character)
        {
            cout<<name<<" attacks "<<character.getName()<<" with power "<<attackPower<<"!"<<endl;
            character.takeDamage(attackPower);
        }
        bool isAlive() const
        {
            return health>0;
        }
        int getBossAttackPower() const
        {
            return attackPower;
        }
};
class GameEngine
{
    public:
        void StartGame(vector<BaseCharacter*>& player,BossEnemy& boss)
        {
            cout<<"Game begins! Players vs. Boss"<<endl;
            while(boss.isAlive())
            {
                int c1=0,c2=0,c3=0;
                for(auto p:player)
                {
                    if(!p->isAlive())
                    {
                        cout<<p->getName()<<" is defeated! Game over."<<endl;
                        return;
                    }
                    p->attack();
                    boss.takeDamage(p->getAttackPower());
                    if(!boss.isAlive())
                    {
                        cout << "Boss defeated! Players win!" << endl;
                        return;
                    }
                    c1++;
                    if(c1==3) break;
                }
                cout<<endl;
                for(auto p:player)
                {
                    if(!p->isAlive())
                    {
                        cout<<p->getName()<<" is defeated! Game over."<<endl;
                        return;
                    }
                    boss.attack(*p);
                    //p->takeDamage(boss.getBossAttackPower());
                    if(!boss.isAlive())
                    {
                        cout << "Boss defeated! Players win!" << endl;
                        return;
                    }
                    c2++;
                    if(c2==3) break;
                }
                cout<<endl;
                for(auto p:player)
                {
                    if(!p->isAlive())
                    {
                        cout<<p->getName()<<" is defeated! Game over."<<endl;
                        return;
                    }
                    p->attack();
                    p->useSpecialAbility();
                    boss.takeDamage(p->getAttackPower()+p->getSpecialAbilityPower());
                    if(!boss.isAlive())
                    {
                        cout << "Boss defeated! Players win!" << endl;
                        return;
                    }
                    c3++;
                    if(c3==3) break;
                }
                cout<<endl;
            }
        }       
};
int main()
{
    Warrior w;
    Mage m;
    Archer a;
    BossEnemy b;
    GameEngine gameEngine;
    vector<BaseCharacter*>player={&w,&m,&a};
    gameEngine.StartGame(player,b);
    return 0;
}