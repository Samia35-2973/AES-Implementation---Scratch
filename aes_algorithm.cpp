#include <bits/stdc++.h>
#define FastNFurious ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

deque<deque<string>> sBox, reconTable;

void check(deque<deque<string>> x){
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      cout << x[i][j] << " ";
    }
    cout << '\n';
  }
}

void makeReconTable(){
  //implementing 4x15 recon table
  deque<string> reconRow(15);
  reconRow[0] = "01"; reconRow[1] = "02"; reconRow[2] = "03"; reconRow[3] = "04"; reconRow[4] = "05"; reconRow[5] = "06"; reconRow[6] = "07"; reconRow[7] = "08"; reconRow[8] = "09"; reconRow[9] = "0A"; reconRow[10] = "0B"; reconRow[11] = "0C"; reconRow[12] = "0D"; reconRow[13] = "0E"; reconRow[14] = "0F";
  reconTable.push_back(reconRow);
  reconRow[0] = "00"; reconRow[1] = "00"; reconRow[2] = "00"; reconRow[3] = "00"; reconRow[4] = "00"; reconRow[5] = "00"; reconRow[6] = "00"; reconRow[7] = "00"; reconRow[8] = "00"; reconRow[9] = "00"; reconRow[10] = "00"; reconRow[11] = "00"; reconRow[12] = "00"; reconRow[13] = "00"; reconRow[14] = "00";
  reconTable.push_back(reconRow);
  reconRow[0] = "00"; reconRow[1] = "00"; reconRow[2] = "00"; reconRow[3] = "00"; reconRow[4] = "00"; reconRow[5] = "00"; reconRow[6] = "00"; reconRow[7] = "00"; reconRow[8] = "00"; reconRow[9] = "00"; reconRow[10] = "00"; reconRow[11] = "00"; reconRow[12] = "00"; reconRow[13] = "00"; reconRow[14] = "00";
  reconTable.push_back(reconRow);
  reconRow[0] = "00"; reconRow[1] = "00"; reconRow[2] = "00"; reconRow[3] = "00"; reconRow[4] = "00"; reconRow[5] = "00"; reconRow[6] = "00"; reconRow[7] = "00"; reconRow[8] = "00"; reconRow[9] = "00"; reconRow[10] = "00"; reconRow[11] = "00"; reconRow[12] = "00"; reconRow[13] = "00"; reconRow[14] = "00";
  reconTable.push_back(reconRow);
}

void fillSBox(){
  deque<string> sBoxRow(16);
  sBoxRow[0] = "63"; sBoxRow[1] = "7C"; sBoxRow[2] = "77"; sBoxRow[3] = "7B"; sBoxRow[4] = "F2"; sBoxRow[5] = "6B"; sBoxRow[6] = "6F"; sBoxRow[7] = "C5"; sBoxRow[8] = "30";
  sBoxRow[9] = "01"; sBoxRow[10] = "67"; sBoxRow[11] = "2B"; sBoxRow[12] = "FE"; sBoxRow[13] = "D7"; sBoxRow[14] = "AB"; sBoxRow[15] = "76";
  sBox.push_back(sBoxRow);
  sBoxRow[0] = "CA"; sBoxRow[1] = "82"; sBoxRow[2] = "C9"; sBoxRow[3] = "7D"; sBoxRow[4] = "FA"; sBoxRow[5] = "59"; sBoxRow[6] = "47"; sBoxRow[7] = "F0"; sBoxRow[8] = "AD";
  sBoxRow[9] = "D4"; sBoxRow[10] = "A2"; sBoxRow[11] = "AF"; sBoxRow[12] = "9C"; sBoxRow[13] = "A4"; sBoxRow[14] = "72"; sBoxRow[15] = "C0";
  sBox.push_back(sBoxRow);
  sBoxRow[0] = "B7"; sBoxRow[1] = "FD"; sBoxRow[2] = "93"; sBoxRow[3] = "26"; sBoxRow[4] = "36"; sBoxRow[5] = "37"; sBoxRow[6] = "F7"; sBoxRow[7] = "CC"; sBoxRow[8] = "34";
  sBoxRow[9] = "A5"; sBoxRow[10] = "E5"; sBoxRow[11] = "F1"; sBoxRow[12] = "71"; sBoxRow[13] = "B8"; sBoxRow[14] = "31"; sBoxRow[15] = "15";
  sBox.push_back(sBoxRow);
  sBoxRow[0] = "04"; sBoxRow[1] = "C7"; sBoxRow[2] = "23"; sBoxRow[3] = "C3"; sBoxRow[4] = "18"; sBoxRow[5] = "96"; sBoxRow[6] = "05"; sBoxRow[7] = "9A"; sBoxRow[8] = "07";
  sBoxRow[9] = "12"; sBoxRow[10] = "80"; sBoxRow[11] = "E2"; sBoxRow[12] = "EB"; sBoxRow[13] = "27"; sBoxRow[14] = "B2"; sBoxRow[15] = "75";
  sBox.push_back(sBoxRow);
  sBoxRow[0] = "09"; sBoxRow[1] = "83"; sBoxRow[2] = "2C"; sBoxRow[3] = "1A"; sBoxRow[4] = "1B"; sBoxRow[5] = "6E"; sBoxRow[6] = "5A"; sBoxRow[7] = "A0"; sBoxRow[8] = "52";
  sBoxRow[9] = "3B"; sBoxRow[10] = "D6"; sBoxRow[11] = "B3"; sBoxRow[12] = "29"; sBoxRow[13] = "E3"; sBoxRow[14] = "2F"; sBoxRow[15] = "84";
  sBox.push_back(sBoxRow);
  sBoxRow[0] = "53"; sBoxRow[1] = "D1"; sBoxRow[2] = "00"; sBoxRow[3] = "ED"; sBoxRow[4] = "20"; sBoxRow[5] = "FC"; sBoxRow[6] = "B1"; sBoxRow[7] = "5B"; sBoxRow[8] = "6A";
  sBoxRow[9] = "CB"; sBoxRow[10] = "BE"; sBoxRow[11] = "39"; sBoxRow[12] = "4A"; sBoxRow[13] = "4C"; sBoxRow[14] = "58"; sBoxRow[15] = "CF";
  sBox.push_back(sBoxRow);
  sBoxRow[0] = "D0"; sBoxRow[1] = "EF"; sBoxRow[2] = "AA"; sBoxRow[3] = "FB"; sBoxRow[4] = "43"; sBoxRow[5] = "4D"; sBoxRow[6] = "33"; sBoxRow[7] = "85"; sBoxRow[8] = "45";
  sBoxRow[9] = "F9"; sBoxRow[10] = "02"; sBoxRow[11] = "7F"; sBoxRow[12] = "50"; sBoxRow[13] = "3C"; sBoxRow[14] = "9F"; sBoxRow[15] = "A8";
  sBox.push_back(sBoxRow);
  sBoxRow[0] = "51"; sBoxRow[1] = "A3"; sBoxRow[2] = "40"; sBoxRow[3] = "8F"; sBoxRow[4] = "92"; sBoxRow[5] = "9D"; sBoxRow[6] = "38"; sBoxRow[7] = "F5"; sBoxRow[8] = "BC";
  sBoxRow[9] = "B6"; sBoxRow[10] = "DA"; sBoxRow[11] = "21"; sBoxRow[12] = "10"; sBoxRow[13] = "FF"; sBoxRow[14] = "F3"; sBoxRow[15] = "D2";
  sBox.push_back(sBoxRow);
  sBoxRow[0] = "CD"; sBoxRow[1] = "0C"; sBoxRow[2] = "13"; sBoxRow[3] = "EC"; sBoxRow[4] = "5F"; sBoxRow[5] = "97"; sBoxRow[6] = "44"; sBoxRow[7] = "17"; sBoxRow[8] = "C4";
  sBoxRow[9] = "A7"; sBoxRow[10] = "7E"; sBoxRow[11] = "CD"; sBoxRow[12] = "64"; sBoxRow[13] = "5D"; sBoxRow[14] = "19"; sBoxRow[15] = "73";
  sBox.push_back(sBoxRow);
  sBoxRow[0] = "60"; sBoxRow[1] = "81"; sBoxRow[2] = "4F"; sBoxRow[3] = "DC"; sBoxRow[4] = "22"; sBoxRow[5] = "2A"; sBoxRow[6] = "90"; sBoxRow[7] = "88"; sBoxRow[8] = "46";
  sBoxRow[9] = "EE"; sBoxRow[10] = "B8"; sBoxRow[11] = "14"; sBoxRow[12] = "DE"; sBoxRow[13] = "5E"; sBoxRow[14] = "0B"; sBoxRow[15] = "DB";
  sBox.push_back(sBoxRow);
  sBoxRow[0] = "E0"; sBoxRow[1] = "32"; sBoxRow[2] = "3A"; sBoxRow[3] = "0A"; sBoxRow[4] = "49"; sBoxRow[5] = "06"; sBoxRow[6] = "24"; sBoxRow[7] = "5C"; sBoxRow[8] = "C2";
  sBoxRow[9] = "D3"; sBoxRow[10] = "AC"; sBoxRow[11] = "62"; sBoxRow[12] = "91"; sBoxRow[13] = "95"; sBoxRow[14] = "E4"; sBoxRow[15] = "79";
  sBox.push_back(sBoxRow);
  sBoxRow[0] = "E7"; sBoxRow[1] = "C8"; sBoxRow[2] = "37"; sBoxRow[3] = "6D"; sBoxRow[4] = "8D"; sBoxRow[5] = "D5"; sBoxRow[6] = "4E"; sBoxRow[7] = "A9"; sBoxRow[8] = "6C";
  sBoxRow[9] = "56"; sBoxRow[10] = "F4"; sBoxRow[11] = "EA"; sBoxRow[12] = "65"; sBoxRow[13] = "7A"; sBoxRow[14] = "AE"; sBoxRow[15] = "08";
  sBox.push_back(sBoxRow);
  sBoxRow[0] = "BA"; sBoxRow[1] = "78"; sBoxRow[2] = "25"; sBoxRow[3] = "2E"; sBoxRow[4] = "1C"; sBoxRow[5] = "A6"; sBoxRow[6] = "B4"; sBoxRow[7] = "C6"; sBoxRow[8] = "E8";
  sBoxRow[9] = "DD"; sBoxRow[10] = "74"; sBoxRow[11] = "1F"; sBoxRow[12] = "4B"; sBoxRow[13] = "BD"; sBoxRow[14] = "8B"; sBoxRow[15] = "8A";
  sBox.push_back(sBoxRow);
  sBoxRow[0] = "70"; sBoxRow[1] = "3E"; sBoxRow[2] = "B5"; sBoxRow[3] = "66"; sBoxRow[4] = "48"; sBoxRow[5] = "03"; sBoxRow[6] = "F6"; sBoxRow[7] = "0E"; sBoxRow[8] = "61";
  sBoxRow[9] = "35"; sBoxRow[10] = "57"; sBoxRow[11] = "B9"; sBoxRow[12] = "86"; sBoxRow[13] = "C1"; sBoxRow[14] = "1D"; sBoxRow[15] = "9E";
  sBox.push_back(sBoxRow);
  sBoxRow[0] = "E1"; sBoxRow[1] = "F8"; sBoxRow[2] = "98"; sBoxRow[3] = "11"; sBoxRow[4] = "69"; sBoxRow[5] = "D9"; sBoxRow[6] = "8E"; sBoxRow[7] = "94"; sBoxRow[8] = "9B";
  sBoxRow[9] = "1E"; sBoxRow[10] = "87"; sBoxRow[11] = "E9"; sBoxRow[12] = "CE"; sBoxRow[13] = "55"; sBoxRow[14] = "28"; sBoxRow[15] = "DF";
  sBox.push_back(sBoxRow);
  sBoxRow[0] = "8C"; sBoxRow[1] = "A1"; sBoxRow[2] = "89"; sBoxRow[3] = "0D"; sBoxRow[4] = "BF"; sBoxRow[5] = "E6"; sBoxRow[6] = "42"; sBoxRow[7] = "68"; sBoxRow[8] = "41";
  sBoxRow[9] = "99"; sBoxRow[10] = "2D"; sBoxRow[11] = "0F"; sBoxRow[12] = "B0"; sBoxRow[13] = "54"; sBoxRow[14] = "BB"; sBoxRow[15] = "16";
  sBox.push_back(sBoxRow);
}
int hexToDec(string s){
  //Converting hexadecimal number to Decimal
  int base = 16;
  reverse(s.begin(), s.end());
  int decimal = 0, power=1, n = s.size(), val;
  for(int i=0;i<n;i++){
    if(s[i]>='0' && s[i]<='9') val = s[i]-'0';
    else val = (s[i]-'A')+10;
    decimal += (val*power);
    power*=base;
  }
  return decimal;
}

string decToHex(int n){
  //Converting Decimal number to hexadecimal
  int base = 16;
  string s="";
  while(n){
    int rem = n%base;
    n/=base;
    if(rem>=0 && rem<=9) s+=(rem+'0');
    else s+=((rem-10)+'A');
  }
  reverse(s.begin(), s.end());
  if(s.size()==0) s += "0";
  if(s.size()<2) s = "0" + s;
  return s;
}


deque<deque<string>> addRoundKey(deque<deque<string>> stateMatrix, deque<deque<string>> roundKeyMatrix){
  //Does xor operation between the state matrix and key matrix
  deque<deque<string>> newStateMatrix;
  for(int i=0;i<4;i++){
    deque<string> newStateRow;
    for(int j=0;j<4;j++){
      string x = stateMatrix[i][j], y = roundKeyMatrix[i][j];//retrieves value
      int xorValueInDecimal = hexToDec(x) ^ hexToDec(y);//performing xor
      string newStateCell = decToHex(xorValueInDecimal);
      newStateRow.push_back(newStateCell);
    }
    newStateMatrix.push_back(newStateRow);
  }
  return newStateMatrix;
}

deque<deque<string>> expandKey(deque<deque<string>> roundKeyMatrix, int roundNumber){
  deque<deque<string>> newKeyMatrix;
  string newKey[4][4];
  deque<string> lastColOfCurrent;
  for(int i=0;i<4;i++) lastColOfCurrent.push_back(roundKeyMatrix[i][3]);

  //shifting one up
  lastColOfCurrent.push_back(lastColOfCurrent.front());
  lastColOfCurrent.pop_front();

  //s-box
  for(int i=0;i<4;i++){
    string s = lastColOfCurrent[i];
    string firstDigit = "", lastDigit = "";
    firstDigit += s[0]; lastDigit += s[1];
    int row = hexToDec(firstDigit), col = hexToDec(lastDigit);
    lastColOfCurrent[i] = sBox[row][col];
  }

  //output's 1st col xor current round's key's 1st col
  for(int i=0;i<4;i++){
    newKey[i][0] = (decToHex(hexToDec(roundKeyMatrix[i][0]) ^ hexToDec(lastColOfCurrent[i])));
  }

  //initially next round's first column = output's 1st col xor recon table's roundNumber th col
  for(int i=0;i<4;i++){
    newKey[i][0] = (decToHex(hexToDec(newKey[i][0]) ^ hexToDec(reconTable[i][roundNumber])));
  }

  //Generating next round's remaining columns = next round's prev col xor current round's current col
  for(int i=1;i<4;i++){
    for(int j=0;j<4;j++){
      newKey[j][i] = (decToHex(hexToDec(newKey[j][i-1]) ^ hexToDec(roundKeyMatrix[j][i])));
    }
  }
  for(int i=0;i<4;i++){
    deque<string> temp;
    for(int j=0;j<4;j++){
      temp.push_back(newKey[i][j]);
    }
    newKeyMatrix.push_back(temp);
  }
  return newKeyMatrix;
}

deque<deque<string>> substituteBytes(deque<deque<string>> stateMatrix){
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      string s = stateMatrix[i][j];
      string firstDigit = "", lastDigit = "";
      firstDigit += s[0]; lastDigit += s[1];
      int row = hexToDec(firstDigit), col = hexToDec(lastDigit);
      stateMatrix[i][j] = sBox[row][col];
    }
  }
  return stateMatrix;
}

deque<deque<string>> shiftRow(deque<deque<string>> stateMatrix){
  for(int i=1;i<4;i++){
    for(int j=0;j<i;j++){
      stateMatrix[i].push_back(stateMatrix[i].front());
      stateMatrix[i].pop_front();
    }
  }
  return stateMatrix;
}
deque<deque<int> > multiply(deque<deque<int> > mat1, deque<deque<int> > mat2, int m){
  int n = mat1.size();
  deque<deque<int> > ans(n, deque<int>(n, 0));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      int current = 0;
      for(int k=0;k<m;k++){
        map<int, int> mp;
        int firstt = mat2[k][j], secondd = mat1[i][k];
        for(int mask = 0; mask < 8; mask++){
          if((firstt>>mask)&1LL){
            for(int mask1 = 0; mask1 < 8; mask1++){
              if((secondd>>mask1)&1LL){
                if(mask+mask1 < 8) mp[(mask+mask1)]++;
                else {
                  mp[4]++;
                  mp[3]++;
                  mp[1]++;
                  mp[0]++;
                }
              }
            }
          }
        }
        int temp = 0;
        for(auto it:mp){
          if(it.second&1) temp |= (1LL<<it.first);
        }
        current ^= temp;
      }
      ans[i][j] = current;
    }
  }
  return ans;
}

deque<deque<string>> mixColumn(deque<deque<string>> stateMatrix){
  deque<deque<int>> aMatrix;
  deque<int> aRow(4);
  aRow[0] = 2; aRow[1] = 3; aRow[2] = 1; aRow[3] = 1;
  aMatrix.push_back(aRow);
  aRow[0] = 1; aRow[1] = 2; aRow[2] = 3; aRow[3] = 1;
  aMatrix.push_back(aRow);
  aRow[0] = 1; aRow[1] = 1; aRow[2] = 2; aRow[3] = 3;
  aMatrix.push_back(aRow);
  aRow[0] = 3; aRow[1] = 1; aRow[2] = 1; aRow[3] = 2;
  aMatrix.push_back(aRow);
  deque<deque<int>> stateMatrixDecimal;
  for(int i=0;i<4;i++){
    deque<int> temp;
    for(int j=0;j<4;j++){
      temp.push_back(hexToDec(stateMatrix[i][j]));
    }
    stateMatrixDecimal.push_back(temp);
  }
  deque<deque<int>> multipliedMatrix = multiply(aMatrix, stateMatrixDecimal, 4);

  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      stateMatrix[i][j] = decToHex(multipliedMatrix[i][j]);
    }
  }
  return stateMatrix;
}

void encryption_algo(){
  fillSBox();
  makeReconTable();
  //Declaring roundkey matrix and state matrix
  deque<deque<string>> stateMatrix, roundKeyMatrix;

  cout << "Enter State Matrix(Plaintext):\n";
  //Take State Matrix input
  for(int i=0;i<4;i++){
    deque<string> stateRow;
    for(int j=0;j<4;j++){
      string s;
      cin >> s;
      stateRow.push_back(s);
    }
    stateMatrix.push_back(stateRow);
  }

  cout << "Enter Round Key Matrix:\n";
  //Take Round Key Matrix input
  for(int i=0;i<4;i++){
    deque<string> keyRow;
    for(int j=0;j<4;j++){
      string s;
      cin >> s;
      keyRow.push_back(s);
    }
    roundKeyMatrix.push_back(keyRow);
  }

  int rounds = 10;
  //Start round works
  stateMatrix = addRoundKey(stateMatrix, roundKeyMatrix);
  for(int i=0;i<rounds;i++){
    stateMatrix = substituteBytes(stateMatrix);
    stateMatrix = shiftRow(stateMatrix);
    if(i!=rounds-1) stateMatrix = mixColumn(stateMatrix);
    roundKeyMatrix = expandKey(roundKeyMatrix, i);
    stateMatrix = addRoundKey(stateMatrix, roundKeyMatrix);
    //check(stateMatrix);
  }
  cout << "Encryption Finished!\n";
  cout << "Ciphertext is:\n";
  check(stateMatrix);
}

void start_system(){
  //The main system runs from here
  cout << "Advanced Encryption Standard\n\n";
  cout << "\t1. Encryption\n";
  cout << "\t2. Exit\n\n";
  cout << "Enter the option number: ";
  int op;
  cin >> op;
  switch(op){
    case 1:
      encryption_algo();
      break;
    case 2:
      cout << "Program Closed\n";
      break;
    default:
      cout << "Invalid Choice. Please try again.\n";
      break;
  }
}

int main(){
  start_system();
}
