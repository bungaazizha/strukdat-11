/*
Nama Program	: Exercise
Nama			: Bunga Azizha N
NPM				: 140810180016
Kelas			: B
Tanggal Buat	: 15 Mei 2019
Deskripsi		: Tree
*/
#include<iostream>
using namespace std;

struct Simpul {
	int info;
	Simpul* left;
	Simpul* right;
};

typedef Simpul* pointer;
typedef pointer Tree;

void CreateSimpul (pointer& pBaru){
	pBaru = new Simpul;
	cout<<"Masukkan satu angka : ";
	cin >> pBaru->info;
	pBaru->left = NULL;
	pBaru->right = NULL;
}

void insertBST (Tree& Root, pointer pBaru) {
	if ( Root ==NULL)
		Root = pBaru;
	else if (pBaru->info < Root->info )
		insertBST (Root->left, pBaru);
	else if (pBaru->info >= Root->info )
		insertBST(Root->right, pBaru);
	else
		cout<<"sudah ada";
}

void preOrder (Tree Root) {
	if (Root != NULL ) {
		cout<< Root->info <<" ";
		preOrder(Root->left);
		preOrder(Root->right);
	}
}

void inOrder (Tree Root) {
	if (Root != NULL ) {
		inOrder(Root->left);
		cout<< Root->info <<" ";
		inOrder(Root->right);
	}
}

void postOrder (Tree Root) {
	if (Root != NULL ) {
		postOrder(Root->left);
		postOrder(Root->right);
		cout<< Root->info << " ";
	}
}

int height(Tree Root){
    if (Root==NULL) return 0;
    else{
        int lHeight=height(Root->left);
        int rHeight=height(Root->right);

        if (lHeight>rHeight) return (lHeight+1);
        else return (rHeight+1);
    }
}

void givenLevel(Tree Root, int level){
    if (Root==NULL) 
        return;
    if (level==1) 
        cout << Root->info << " ";
    else if (level>1){
        givenLevel(Root->left,level-1);
        givenLevel(Root->right,level-1);
    }
}

void kedalaman(Tree Root){
    int h=height(Root);
    for (int i=1; i<=h; i++){
        cout << i-1 << ": " <<" [ ";
        givenLevel(Root,i);
        cout<< "]"<< endl;
    }
}

void levelOrder(Tree Root){
    int h=height(Root);
    for (int i=1; i<=h; i++){
        cout << i << ": " <<" [ ";
        givenLevel(Root,i);
        cout<< "]"<< endl;
    }
}

void Anak(Tree Root, pointer pBaru){
    pBaru= Root;
    if(pBaru!=NULL){
        cout<<"Parent Node = "<<pBaru->info<<endl;
        if(pBaru->left == NULL)
            cout<<"Left Child = NULL"<<endl;
        else
            cout<<"Left Child = "<<pBaru->left->info<<endl;
                     
        if(pBaru->right == NULL)
            cout<<"Right Child = NULL"<<endl;
        else
            cout<<"Right Child = "<<pBaru->right->info<<endl;
  
  cout<<endl;
        Anak(Root->left, pBaru);
        Anak(Root->right, pBaru);
    }
}

main() {
	Tree T;
	pointer p;
	int n, pil;
	char jawab;
	
	do{
        system("CLS");
     cout<<"\tProgram TREE"<<endl;
     cout<<"========================="<<endl;
     cout<<"| 1. Insert BST\t\t|"<<endl;
     cout<<"| 2. Pre Order\t\t|"<<endl;
     cout<<"| 3. In Order\t\t|"<<endl;
     cout<<"| 4. Post Order\t\t|"<<endl;
     cout<<"| 5. Kedalaman\t\t|"<<endl;
     cout<<"| 6. Level\t\t|"<<endl;
     cout<<"| 7. Anak\t\t|"<<endl;
     cout<<"| 8. Exit\t\t|"<<endl;
     cout<<"========================="<<endl;
     cout<<"Pilihan : ";cin>>pil;
	
	switch(pil){
		case 1:
			cout<<"\nMasukkan jumlah angka = "; cin>>n;
			cout<<endl;
				for ( int i=0; i <n; i++){
					CreateSimpul(p);
					insertBST(T,p);
				}
		break;
         
    	case 2:
			cout<<"\nPre Order"<<endl;
			preOrder(T);
		break;
	
		case 3:
			cout<<"\nIn Order"<<endl;
			inOrder(T);
		break;
	
		case 4:
			cout<<"\nPost Order"<<endl;
			postOrder(T);
		break;
	
		case 5:
			cout<<"Kedalaman"<<endl;
			kedalaman(T);
		break;
	
		case 6:
			cout<<"Level"<<endl;
			levelOrder(T);
		break;
	
		case 7:
			cout<<"Anak"<<endl;
			Anak(T,p);
		break;
	
		case 8:
		cout<<"\nThank You ! Bye ! "<<endl;
            return 0;
            break;
			
		default:
        	cout<<"Input Salah, Harap Cek dan Coba Lagi !"<<endl;
        break;
    }
    cout<<"\nKembali ke menu?(Y/N)"; cin>>jawab;
	}
	while(jawab=='y'|| jawab=='Y');
}
