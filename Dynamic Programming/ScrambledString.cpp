Scrambled String:

Input:
s = "break"
t = "rbeak"

Output:
True

Code:

bool Scrambled(string s1, string s2) {
	if(s1.compare(s2)==0)
		return True;
	if(s1.length()<=1)		
		return False;
	boolean Flag = False;
	for(int i=0; i<s1.lenth(); i++){
		if( ( Scrambled(s1.substr(0,i), s2.substr(n-i, i))==True && Scrambled(s1.substr(i, n-i), s2.substr(0, n-i))== True ) || ( Scrambled(s1.substr(0,i), s2.substr(0, i))== True && Scrambled(s1.substr(i, n-i), s2.substr(i, n-i))== True ) )
		{
			Flag = True;
			break;
		}
	} 
	return Flag;
}

int main() { 
	string a,b;
	cout<<"Enter Strings...";
	cin>>a>>b;
	if(a.length()==b.length()){
		bool z = Scrambled(a,b);
		cout<<z;}
	else
		cout<<"These string cant be Scrambled";
	return 0;
}