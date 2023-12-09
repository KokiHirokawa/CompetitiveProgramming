#include <iostream>
#include <bitset>

using namespace std;

#define BIT_FLAG_0 (1 << 0) // 0000 0001
#define BIT_FLAG_1 (1 << 1) // 0000 0010
#define BIT_FLAG_2 (1 << 2) // 0000 0100
#define BIT_FLAG_3 (1 << 3) // 0000 1000
#define BIT_FLAG_4 (1 << 4) // 0001 0000
#define BIT_FLAG_5 (1 << 5) // 0010 0000
#define BIT_FLAG_6 (1 << 6) // 0100 0000
#define BIT_FLAG_7 (1 << 7) // 1000 0000

int main() {
    // AND
    {
        int a = 45;
        int b = 25;

        cout << (a & b) << endl;
    }

    // OR
    {
        int a = 45;
        int b = 25;

        cout << (a | b) << endl;
    }

    // bitset
    {
        int a = 0x2d;
        int b = 0x19;

        cout << a << " AND " << b << " = " << (a & b) << endl;
        cout << bitset<8>(a) << " AND " << bitset<8>(b) << " = " << bitset<8>(a & b) << endl;
    }

    // bit shift
    {
        cout << bitset<8>(7) << " = " << bitset<8>((1 << 2) | (1 << 1) | (1 << 0)) << endl;

        int a = 21;

        // i番目のフラグが立っているかどうか
        cout << "[";
        for (int i = 0; i < 8; i++) if (a & (1 << i)) cout << i << ",";
        cout << "]" << endl;

        // i番目のフラグが立っていないかどうか
        cout << "[";
        for (int i = 0; i < 8; i++) if (!(a & (1 << i))) cout << i << ",";
        cout << "]" << endl;

        // i番目のフラグを立てる
        cout << (a | (1 << 3)) << endl;

        // i番目のフラグを消す
        cout << (a & ~(1 << 4)) << endl;

        // 何個のフラグが立っているか
        // GCC のビルトイン関数
        cout << __builtin_popcount(a) << endl;
    }

    // bit mask
    {
        const unsigned int BIT_FLAG_DAMAGE = (1 << 0); // HP が満タンでないか
        const unsigned int BIT_FLAG_POISON = (1 << 1); // 毒状態か
        const unsigned int BIT_FLAG_PARALYSIS = (1 << 2); // 麻痺状態か
        const unsigned int BIT_FLAG_DEAD = (1 << 3); // 戦闘不能状態か

        const unsigned int MASK_ATTACK = BIT_FLAG_DAMAGE;
        const unsigned int MASK_PUNCH = BIT_FLAG_DAMAGE | BIT_FLAG_PARALYSIS;
        const unsigned int MASK_DEFEAT = BIT_FLAG_DAMAGE | BIT_FLAG_DEAD;
        const unsigned int MASK_POISON_PARALYSIS = BIT_FLAG_POISON | BIT_FLAG_PARALYSIS;

        unsigned int status = 0;
        printf("start: %s\n", bitset<4>(status).to_string().c_str());

        status |= MASK_ATTACK;
        printf("attacked: %s\n", bitset<4>(status).to_string().c_str());

        status |= MASK_PUNCH;
        printf("punched: %s\n", bitset<4>(status).to_string().c_str());

        if (status & MASK_POISON_PARALYSIS) printf("You are poisoned and paralyzed.\n");

        status &= ~MASK_POISON_PARALYSIS;
        printf("cured: %s\n", bitset<4>(status).to_string().c_str());

        status |= MASK_DEFEAT;
        printf("defeated: %s\n", bitset<4>(status).to_string().c_str());

        status &= ~MASK_DEFEAT;
        printf("revived: %s\n", bitset<4>(status).to_string().c_str());
    }

    return 0;
}