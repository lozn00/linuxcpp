#include<iostream>
#include "BaseObj.h"
using namespace std;
class ParentClass{
	public:
	 // virtual		void method1();
	virtual void method1(){
		cout<<" hello  parent class ";
	}

};
class ParentClass1{
	public:
		virtual void method1(){
			cout<<" call metho1 (parent)";
		}

};
class ChildClass1 :ParentClass1{
			public:
				void method1(){
					cout<<" childclas 1 metho1 call \n";
				}
};
class ChildClass:public ParentClass{
		private:
		int privateValue;

			public:
			int publicValue;
		friend  void  friendMethod(ChildClass childClass);
			void method1(){

				 cout<<"hello method1  from child class\n";
		}
		ChildClass(){
			cout<<" ChildClass  construction"<<endl;
			privateValue=5;
			publicValue=10;
		}

		~ChildClass(){
			cout<<" child Class destory"<<endl;
		}
		
};

 void friendMethod(ChildClass childClass){
			cout<<"this is fridnd "<<childClass.privateValue<<endl;
}

	int main(){
	cout<<"wellcome study cpp \n";

	ChildClass child;

	child.method1();
	friendMethod(child);
	// private cannot access ,but  can access by  friend .cout<<" child privateValue:"<<child.privateValue<<endl;
	cout<<" child publicValue:"<<child.publicValue<<endl;
	ChildClass1 child1;

	child1.method1();
	cout<<" use pointer................... "<<endl;
	ParentClass* parentPtr=&child;//conversion from ‘ChildClass*’ to non-scalar type ‘ParentClass’ requested ->define ptr must  classname* varname
	parentPtr->method1();//if parent method [not defined virtual will c all parent wufa shiyong wu],

	ChildClass* childPtr=&child;
	childPtr->method1();

	return 0;
//theme "color_scheme": "Packages/Color Scheme - Default/Sixteen.sublime-color-scheme",
//ctrl +b  run 
//ctrl +shift+p open command  
	////https://github.com/dempfi/ayu/releases   unzip packages dir,  click menu choose preference choose borser package 
//ayu search theme  or github  preference broser package
}

	/*
if  you want use vim mode ,defined:

	"ignored_packages":
	[
	],
g++ compile 
g++ *.cpp -o outfile
	*/



// https://medium.com/@PopularDemand/setting-sublime-text-3-as-default-editor-ubuntu-498163c33943

/*

ln -s sublime_text /usr/bin/subl

[Desktop Entry]
Name=Visual Studio Code
Comment=Code Editing. Redefined.
GenericName=Text Editor
Exec=/usr/share/code/code --unity-launch %F
Icon=code
Type=Application
StartupNotify=true
StartupWMClass=Code
Categories=Utility;TextEditor;Development;IDE;
MimeType=text/plain;inode/directory;
Actions=new-empty-window;
Keywords=vscode;

X-Desktop-File-Install-Version=0.22

[Desktop Action new-empty-window]
Name=New Empty Window
Exec=/usr/share/code/code --new-window %F
Icon=code

*/
