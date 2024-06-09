#include <time.h>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;


template<class T> class vec{

private:
	mutable int jmax;
	int length;
	int *jrow;
	T* val;

	mutable std::string Err;
public:

	vec(int a=0, T b=0, T c = 0, std::string s = ""){
		length = a;
		jmax = a;
		val = new T [length];
		val -=1;
		jrow = new int [length];
		jrow -=1;
		for(int i=1; i<length; i++){ val[i] = b; jrow[i] = i;}
		Err = s;
		}


	~vec(){
		jrow +=1;
		delete [] jrow;

		val +=1;
		delete [] val;
//		delete [] neg;
	}
	

	vec(const vec& );
	vec& operator=(const vec& );

	T operator[](int) const;
	T& operator()(int);


	void resize(int ); 
	int size(){return length; }
	void operator += (int);
	void operator -= (int);
	void Exit()const {cout<<Err<<endl; exit(EXIT_FAILURE);}
	int jcheck(int)const;
	int row(int)const;
	vec operator+(const vec&)const;
	vec operator*(double );
	template<class S>
	friend void ssum (vec<S>&, vec<S>&, vec<S>&, double);
};
 template <class T> int vec<T>::jcheck(int a)const{
	int temp = -1;
	jmax = 1;
	for (int i=1; i<=length; i++){
//cout<<"jrow["<<i<<"] ="<<jrow[i]<<'\t';
		if(jrow[i]>0) jmax++;
		if(jrow[i]==a){ temp = i;
			break;}
	}
	return temp;
}
 template <class T> vec<T>::vec(const vec& V1){
	length = V1.length;
	val = new T [length];
	val -=1;
	jrow = new int [length];
	jrow -=1;
	for(int i=1; i<=length; i++) {val[i] = V1.val[i]; jrow[i] = V1.jrow[i];}
}

template <class T>  T& vec<T>::operator()(int a) {
	int  temp;
	temp = jcheck(a);

	if(temp >0){
		return val[temp];
	}

	else{
		if(jmax<=length){
			jrow[jmax] = a;
			return val[jmax];
		}else{

			T* temp;
			temp = new T [length];
			temp -=1;
			int *jTemp;
			jTemp = new int [length];
			jTemp -=1;
 
			for (int i=1; i<=length; i++) { temp[i] = val[i]; jTemp[i] = jrow[i];}

			val +=1;
			delete [] val;
			jrow +=1;
			delete [] jrow;

			length++;
	
			val = new T[length];
			val -=1;
			jrow = new int [length];
			jrow -=1;
	
			for(int i=1; i<length; i++) {val[i] = temp[i]; jrow[i] = jTemp[i];}

			jrow[length] = a;
			val[length] = T(0);
			temp +=1;
			delete [] temp;
			jTemp +=1;
			delete [] jTemp;
			return val[length];
		}
	}	

}

template <class T>  T vec<T>::operator[](int a) const {
	int  temp;
	temp = jcheck(a);

	if(temp >0){
		return val[temp];
	}

	else{
		return 	T(0); //neg[0];
		
	}	

}
template <class T> vec<T>& vec<T>::operator=(const vec<T>& V1){

	if(this != &V1){
		if(length !=V1.length) resize(V1.length);// {Err = "Error, two vectors are not match\n"; Exit();}
		for(int i=1; i<=length; i++) {val[i] = V1.val[i]; jrow[i] = V1.jrow[i];}
	}
	return *this;
}
template <class T> void vec<T>::operator -=(int b){

	int a = jcheck(b);
	
if(a>0){
	T* temp;
	int *jTemp;

	temp = new T [length];
	temp -=1;
	jTemp = new int [length];
	jTemp -=1;

	for (int i=1; i<=length; i++) {temp[i] = val[i]; jTemp[i] = jrow[i];}

	val +=1;
	delete [] val;
	jrow +=1;
	delete [] jrow;
	
	length--;
	
	val = new T[length];
	val -=1;
	jrow = new int [length];
	jrow -=1;
	for(int i=1; i<a; i++) {val[i] = temp[i]; jrow[i] = jTemp[i];}
	for(int i=a; i<=length; i++) {val[i] = temp[i+1]; jrow[i] = jTemp[i+1];}

	temp +=1;
	delete [] temp;
	jTemp +=1;
	delete [] jTemp;
} else{
	Err = "\nSorry, The requested element to remove is not belongs to this array\n";
	Exit();
}

}

template <class T> void vec<T>::operator += (int a){

  int b = jcheck(a);

  if(b<=0){
	T* temp;
	temp = new T [length];
	temp -=1;
	int *jTemp;
	jTemp = new int [length];
	jTemp -=1;
 
	for (int i=1; i<=length; i++) { temp[i] = val[i]; jTemp[i] = jrow[i];}

	val +=1;
	delete [] val;
	jrow +=1;
	delete [] jrow;

	length++;
	
	val = new T[length];
	val -=1;
	jrow = new int [length];
	jrow -=1;
	
	for(int i=1; i<length; i++) {val[i] = temp[i]; jrow[i] = jTemp[i];}

	jrow[length] = a;
	val[length] = T(0);

	temp +=1;
	delete [] temp;
	jTemp +=1;
	delete [] jTemp;

//	return val[length];
 }
}

template <class T> void vec<T>::resize(int a){

	int ol;
	T* temp;
	ol = length;
	temp = new T [ol];
	temp -=1;
	int *jtemp ;
	jtemp = new int [ol];
	jtemp -=1;

	for (int i=1; i<=ol; i++) {temp[i] = val[i]; jtemp[i] = jrow[i];}

	val +=1;
	delete [] val;
	jrow +=1;
	delete [] jrow;

	length = a;

	val = new T [length];
	val -=1;
	jrow = new int [length];
	jrow -=1;

	
	if(ol<length){
		for(int i=1; i<=ol; i++) {val[i] = temp[i]; jrow[i] = jtemp[i];}
		for(int i=ol+1; i<=length; i++){val[i] = T(0); jrow[i] = T(0);}
	}else{
		for(int i=1; i<=length; i++)  {val[i] = temp[i]; jrow[i] = jtemp[i];}
	}

	temp +=1;
	jtemp +=1;

	delete [] temp;
	delete [] jtemp;

}

 template <class T> int vec<T>::row(int a)const{
	if(a<=length){
		return jrow[a];
	}else{
		Err=" The requested value for row is greater than what we have, i.e., length\n";
		Exit();
		return T(0);
	}
 }

 template <class T> vec<T> vec<T>::operator+(const vec<T>& V1) const {
	
	vec<T> vt = *this;

	int k;

	for(int i=1; i<=V1.length; i++) {
		k = V1.row(i);
		vt(k) = vt[k] +  V1[k];

	}

	return vt;
}

 template <class T> vec<T> vec<T>::operator*(double cof) {
	
	vec<T> vt = *this;

	for(int i=1; i<=vt.length; i++)  vt(i) = vt[i]*cof;

	return vt;
}
 template <class T> 
	void ssum(vec<T>& V1, vec<T>& V2, vec<T>& V3, double cof){

	int k;

	for(int i=1; i<=V2.length; i++){
		k = V2.row(i);
		V1(k) = V1[k]+V2[k];
	}

	for(int i=1; i<=V3.length; i++){
		k = V3.row(i);
		V1(k) = V1[k]+cof*V3[k];
	}

}
