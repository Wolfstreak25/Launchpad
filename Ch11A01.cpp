#include <iostream>

using namespace std;

class Player
{
  private:
    int Health=100;
    int MaxDamage=25;
    int MinDamage=15;
    int Healing=20;
    int Defence=20;

  public:
    Player()
      { 
        cout<<"\nPlayer Stats_______";
        cout<<"\nPlayer Health : "<<Health<<endl;
        cout<<"Enemy Attack Damage : "<<MinDamage<<" To "<<MaxDamage<<endl;
        cout<<"Player Healing Capacity : "<<Healing<<endl;
        cout<<"Player Defence Strength : "<<Defence<<endl;
      }

    int GetHealth()
      {
        cout<<endl<<"Player Health\n";
        return Health;
      }

    void TakeDamage(int Damage)
      {
        cout<<"\nEnemy Attacked\n";
        Health=Health-Damage;
        if(Health<=0)
        {
          cout<<"\nPlayer Died\nGame Over";
        }
        else
        {
          cout<<"\nPlayer Health\n"<<Health<<endl;
        }
      }

    int GiveDamage()
      {
        int Damage;
        cout<<"\nHero Attacked\n";
        Damage=rand()%(MaxDamage-MinDamage)+MinDamage;
        cout<<"\nDamage dealt to enemy\n"<<Damage<<endl;
        return Damage;
      
      }
    
    int Heal()
      {
       if(Health < 100)
         {
           cout<<"\nPlayer Health"<<endl<<Health<<endl;
           Health=Health+Healing;
           cout<<"\nNew Player Health"<<endl<<Health<<endl;   
         }

        return 0;
      }
};

class Enemy
{
  private:
    int Health=100;
    int MaxDamage=25;
    int MinDamage=15;
    int Healing=20;
    int Defence=20;

  public:

    Enemy()
      { 
        cout<<"\nEnemy 1_______\n";
        cout<<"\nEnemy Stats_______";
        cout<<"\nEnemy Health : "<<Health<<endl;
        cout<<"Enemy Attack Damage : "<<MinDamage<<" To "<<MaxDamage<<endl;
        cout<<"Enemy Healing Capacity : "<<Healing<<endl;
        cout<<"Enemy Defence Strength : "<<Defence<<endl;
      }

    int GetHealth()
      {
        cout<<endl<<"Enemy Health\n";
        return Health;
      }

    void TakeDamage(int Damage)
      {
        cout<<"\nPlayer Attacked\n";
        Health=Health-Damage;
        if(Health<=0)
        {
          cout<<"\nPlayer Died\nGame Over\n";
        }
        else
        {
          cout<<"\nEnemy Health\n"<<Health<<endl;
        }
      }

    int GiveDamage()
      {
        int Damage;
        cout<<"\nEnemy Attacked\n";
        Damage=rand()%(MaxDamage-MinDamage)+MinDamage;
        cout<<"\nDamage dealt to player\n"<<Damage<<endl;
        return Damage;
      }

 /*   int Heal()
      {
       if(Health < 100)
       {
         cout<<"\nEnemy Health"<<endl<<Health<<endl;
         Health=Health+Healing;
         cout<<"\nNew Enemy Health"<<endl<<Health<<endl;   
       }
       return 0;
      }
 */
};

void GameLoop(Player player, Enemy enemy)
{
    char PlayerChoioce;
    do
    {
     jump:
        
        cout<<"\n Press A to attack\nPress H to Heal\n";
        cin>>PlayerChoioce;

        if(PlayerChoioce == 'a' || PlayerChoioce== 'A')
        {
          system ("clear");
            enemy.TakeDamage(player.GiveDamage());
            if(enemy.GetHealth()>0)
            {
                cout<<"\nIt's My turn Now\n";
                player.TakeDamage(enemy.GiveDamage());
            }
            
            
        }
        else if(PlayerChoioce == 'h' || PlayerChoioce== 'H')
        {
          system ("clear");
            player.Heal();
            if(enemy.GetHealth()>0)
            {
                cout<<"\nIt's My turn Now\n";
                player.TakeDamage(enemy.GiveDamage());
            }
        }
        else
        {
          system ("clear");
            cout<<"\nInvalid choice\nEnter Again\n";
            goto jump;
        }
    } while(player.GetHealth() > 0 && enemy.GetHealth() > 0);
}

void GameStory()
{
  cout << "The Story!\n";
  cout << "                            _________________________________\n";
  cout << "\n";
}

int main() 
{
    bool UserInput;
    GameStory();

    do
    {
        cout<<"\nPress 1 to play\nPress 0 to exit\n";
        cin>>UserInput;
        if (UserInput == true)
        {
            Player player1;
            Enemy enemy1;
            GameLoop(player1,enemy1);
        }
        else
        {
            cout<<"\nThanks for playing\n";
        }
    } while(UserInput=true);
  return 0;
}