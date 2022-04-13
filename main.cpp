
#include <cstdlib>
#include <QString>
#include <QVector>
#include <QTextStream>

int myRand(int min, int max){
    return rand() % (max-min+1) + min ;
}

int countDigits(int n) {
    int count = 0;
    while (n != 0) {
        n = n/10;
        count++;
    }
    return count;
}

QVector<int> randomPerm(int n, unsigned key){
    QVector<int> perm;
    srand(key);
    for(int i = 0; i < countDigits(n); i++){
        int j = myRand(0, n);
        perm.append(j);
    }
    return perm;
}

QString shift(const QString& text, unsigned key){
    srand(key);
    QString stringUpdate;
    foreach(const QChar ch, text){
        int ascii = ch.toLatin1();
        int update = ascii + myRand(0, 128);
        if(update > 128){
            update -= 128;
        }
        stringUpdate.append(update);
    }
    return stringUpdate;
}

QString unshift(const QString& text, unsigned key){
    srand(key);
    QString stringUpdate;
    foreach(const QChar ch, text){
        int ascii = ch.toLatin1();
        int update = ascii - myRand(0, 128);
        if (update < 0) {
            update += 128;
        }
        stringUpdate.append(update);
    }
    return stringUpdate;
}

QString permute(const QString& text, unsigned key){
    srand(key);
    QString perm;
    foreach(const QChar ch, text) {
        int update = ch.toLatin1();
        QVector<int> ascii = randomPerm(update, key);
        foreach(int n, ascii){
            perm.append(n); 
        }
    }
    
    return perm;
}

QString unpermute(const QString& srctext, unsigned key){
    srand(key); 
    QVector<int> unperm; 
    foreach(const QChar ch, srctext){
        
    }
}

int main() {
    QTextStream stream (stdout);
    unsigned key = 123;
    int num = 200;
    stream << "Before permutation: " << endl;
    stream  << "After permutation: " << endl;
    QVector<int> perm = randomPerm(num, key);
    foreach(int num, perm){
        stream << num;
    }

    QString test = "Hello World";
    QString shifted = shift(test, key);
    QString unshifted = unshift(shifted, key);
    stream << "Before the shift: " << test << endl;
    stream << "After the shift: " << shifted << endl;
    stream << "Returning the value back: " << unshifted << endl;

    QString test2 = "Hello World and all who inhabit it";
    QString permuted = permute(test2, key);
    QString unpermuted = unpermute(permuted, key);
    stream << "Before the perumtation: " << test2 << endl;
    stream << "After the permutation: " << permuted << endl;
    stream << "After the unpermutation:" << unpermuted << endl;
    return 0;
}
