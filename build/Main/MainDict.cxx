// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIgeniedIappdIjiangldIlampmInewdIEScatteringdILiteFMWKdIbuilddIMaindIMainDict

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "GENIEEventHisto.h"
#include "Maker.h"
#include "TArray2D.h"
#include "TArray3D.h"
#include "sample.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *MaincLcLMaker_Dictionary();
   static void MaincLcLMaker_TClassManip(TClass*);
   static void *new_MaincLcLMaker(void *p = 0);
   static void *newArray_MaincLcLMaker(Long_t size, void *p);
   static void delete_MaincLcLMaker(void *p);
   static void deleteArray_MaincLcLMaker(void *p);
   static void destruct_MaincLcLMaker(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Main::Maker*)
   {
      ::Main::Maker *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Main::Maker));
      static ::ROOT::TGenericClassInfo 
         instance("Main::Maker", "Maker.h", 68,
                  typeid(::Main::Maker), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &MaincLcLMaker_Dictionary, isa_proxy, 4,
                  sizeof(::Main::Maker) );
      instance.SetNew(&new_MaincLcLMaker);
      instance.SetNewArray(&newArray_MaincLcLMaker);
      instance.SetDelete(&delete_MaincLcLMaker);
      instance.SetDeleteArray(&deleteArray_MaincLcLMaker);
      instance.SetDestructor(&destruct_MaincLcLMaker);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Main::Maker*)
   {
      return GenerateInitInstanceLocal((::Main::Maker*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::Main::Maker*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *MaincLcLMaker_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Main::Maker*)0x0)->GetClass();
      MaincLcLMaker_TClassManip(theClass);
   return theClass;
   }

   static void MaincLcLMaker_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *MaincLcLsample_Dictionary();
   static void MaincLcLsample_TClassManip(TClass*);
   static void *new_MaincLcLsample(void *p = 0);
   static void *newArray_MaincLcLsample(Long_t size, void *p);
   static void delete_MaincLcLsample(void *p);
   static void deleteArray_MaincLcLsample(void *p);
   static void destruct_MaincLcLsample(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Main::sample*)
   {
      ::Main::sample *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Main::sample));
      static ::ROOT::TGenericClassInfo 
         instance("Main::sample", "sample.h", 24,
                  typeid(::Main::sample), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &MaincLcLsample_Dictionary, isa_proxy, 4,
                  sizeof(::Main::sample) );
      instance.SetNew(&new_MaincLcLsample);
      instance.SetNewArray(&newArray_MaincLcLsample);
      instance.SetDelete(&delete_MaincLcLsample);
      instance.SetDeleteArray(&deleteArray_MaincLcLsample);
      instance.SetDestructor(&destruct_MaincLcLsample);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Main::sample*)
   {
      return GenerateInitInstanceLocal((::Main::sample*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::Main::sample*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *MaincLcLsample_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Main::sample*)0x0)->GetClass();
      MaincLcLsample_TClassManip(theClass);
   return theClass;
   }

   static void MaincLcLsample_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_MaincLcLMaker(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::Main::Maker : new ::Main::Maker;
   }
   static void *newArray_MaincLcLMaker(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::Main::Maker[nElements] : new ::Main::Maker[nElements];
   }
   // Wrapper around operator delete
   static void delete_MaincLcLMaker(void *p) {
      delete ((::Main::Maker*)p);
   }
   static void deleteArray_MaincLcLMaker(void *p) {
      delete [] ((::Main::Maker*)p);
   }
   static void destruct_MaincLcLMaker(void *p) {
      typedef ::Main::Maker current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Main::Maker

namespace ROOT {
   // Wrappers around operator new
   static void *new_MaincLcLsample(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::Main::sample : new ::Main::sample;
   }
   static void *newArray_MaincLcLsample(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::Main::sample[nElements] : new ::Main::sample[nElements];
   }
   // Wrapper around operator delete
   static void delete_MaincLcLsample(void *p) {
      delete ((::Main::sample*)p);
   }
   static void deleteArray_MaincLcLsample(void *p) {
      delete [] ((::Main::sample*)p);
   }
   static void destruct_MaincLcLsample(void *p) {
      typedef ::Main::sample current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Main::sample

namespace ROOT {
   static TClass *vectorlEvectorlEdoublegRsPgR_Dictionary();
   static void vectorlEvectorlEdoublegRsPgR_TClassManip(TClass*);
   static void *new_vectorlEvectorlEdoublegRsPgR(void *p = 0);
   static void *newArray_vectorlEvectorlEdoublegRsPgR(Long_t size, void *p);
   static void delete_vectorlEvectorlEdoublegRsPgR(void *p);
   static void deleteArray_vectorlEvectorlEdoublegRsPgR(void *p);
   static void destruct_vectorlEvectorlEdoublegRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<vector<double> >*)
   {
      vector<vector<double> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<vector<double> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<vector<double> >", -2, "vector", 216,
                  typeid(vector<vector<double> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEvectorlEdoublegRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<vector<double> >) );
      instance.SetNew(&new_vectorlEvectorlEdoublegRsPgR);
      instance.SetNewArray(&newArray_vectorlEvectorlEdoublegRsPgR);
      instance.SetDelete(&delete_vectorlEvectorlEdoublegRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEvectorlEdoublegRsPgR);
      instance.SetDestructor(&destruct_vectorlEvectorlEdoublegRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<vector<double> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<vector<double> >*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEvectorlEdoublegRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<vector<double> >*)0x0)->GetClass();
      vectorlEvectorlEdoublegRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEvectorlEdoublegRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEvectorlEdoublegRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<vector<double> > : new vector<vector<double> >;
   }
   static void *newArray_vectorlEvectorlEdoublegRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<vector<double> >[nElements] : new vector<vector<double> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEvectorlEdoublegRsPgR(void *p) {
      delete ((vector<vector<double> >*)p);
   }
   static void deleteArray_vectorlEvectorlEdoublegRsPgR(void *p) {
      delete [] ((vector<vector<double> >*)p);
   }
   static void destruct_vectorlEvectorlEdoublegRsPgR(void *p) {
      typedef vector<vector<double> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<vector<double> >

namespace ROOT {
   static TClass *vectorlEvectorlETH2DmUgRsPgR_Dictionary();
   static void vectorlEvectorlETH2DmUgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEvectorlETH2DmUgRsPgR(void *p = 0);
   static void *newArray_vectorlEvectorlETH2DmUgRsPgR(Long_t size, void *p);
   static void delete_vectorlEvectorlETH2DmUgRsPgR(void *p);
   static void deleteArray_vectorlEvectorlETH2DmUgRsPgR(void *p);
   static void destruct_vectorlEvectorlETH2DmUgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<vector<TH2D*> >*)
   {
      vector<vector<TH2D*> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<vector<TH2D*> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<vector<TH2D*> >", -2, "vector", 216,
                  typeid(vector<vector<TH2D*> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEvectorlETH2DmUgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<vector<TH2D*> >) );
      instance.SetNew(&new_vectorlEvectorlETH2DmUgRsPgR);
      instance.SetNewArray(&newArray_vectorlEvectorlETH2DmUgRsPgR);
      instance.SetDelete(&delete_vectorlEvectorlETH2DmUgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEvectorlETH2DmUgRsPgR);
      instance.SetDestructor(&destruct_vectorlEvectorlETH2DmUgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<vector<TH2D*> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<vector<TH2D*> >*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEvectorlETH2DmUgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<vector<TH2D*> >*)0x0)->GetClass();
      vectorlEvectorlETH2DmUgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEvectorlETH2DmUgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEvectorlETH2DmUgRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<vector<TH2D*> > : new vector<vector<TH2D*> >;
   }
   static void *newArray_vectorlEvectorlETH2DmUgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<vector<TH2D*> >[nElements] : new vector<vector<TH2D*> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEvectorlETH2DmUgRsPgR(void *p) {
      delete ((vector<vector<TH2D*> >*)p);
   }
   static void deleteArray_vectorlEvectorlETH2DmUgRsPgR(void *p) {
      delete [] ((vector<vector<TH2D*> >*)p);
   }
   static void destruct_vectorlEvectorlETH2DmUgRsPgR(void *p) {
      typedef vector<vector<TH2D*> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<vector<TH2D*> >

namespace ROOT {
   static TClass *vectorlEstringgR_Dictionary();
   static void vectorlEstringgR_TClassManip(TClass*);
   static void *new_vectorlEstringgR(void *p = 0);
   static void *newArray_vectorlEstringgR(Long_t size, void *p);
   static void delete_vectorlEstringgR(void *p);
   static void deleteArray_vectorlEstringgR(void *p);
   static void destruct_vectorlEstringgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<string>*)
   {
      vector<string> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<string>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<string>", -2, "vector", 216,
                  typeid(vector<string>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEstringgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<string>) );
      instance.SetNew(&new_vectorlEstringgR);
      instance.SetNewArray(&newArray_vectorlEstringgR);
      instance.SetDelete(&delete_vectorlEstringgR);
      instance.SetDeleteArray(&deleteArray_vectorlEstringgR);
      instance.SetDestructor(&destruct_vectorlEstringgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<string> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<string>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEstringgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<string>*)0x0)->GetClass();
      vectorlEstringgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEstringgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEstringgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<string> : new vector<string>;
   }
   static void *newArray_vectorlEstringgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<string>[nElements] : new vector<string>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEstringgR(void *p) {
      delete ((vector<string>*)p);
   }
   static void deleteArray_vectorlEstringgR(void *p) {
      delete [] ((vector<string>*)p);
   }
   static void destruct_vectorlEstringgR(void *p) {
      typedef vector<string> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<string>

namespace ROOT {
   static TClass *vectorlEdoublegR_Dictionary();
   static void vectorlEdoublegR_TClassManip(TClass*);
   static void *new_vectorlEdoublegR(void *p = 0);
   static void *newArray_vectorlEdoublegR(Long_t size, void *p);
   static void delete_vectorlEdoublegR(void *p);
   static void deleteArray_vectorlEdoublegR(void *p);
   static void destruct_vectorlEdoublegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<double>*)
   {
      vector<double> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<double>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<double>", -2, "vector", 216,
                  typeid(vector<double>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEdoublegR_Dictionary, isa_proxy, 4,
                  sizeof(vector<double>) );
      instance.SetNew(&new_vectorlEdoublegR);
      instance.SetNewArray(&newArray_vectorlEdoublegR);
      instance.SetDelete(&delete_vectorlEdoublegR);
      instance.SetDeleteArray(&deleteArray_vectorlEdoublegR);
      instance.SetDestructor(&destruct_vectorlEdoublegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<double> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<double>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEdoublegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<double>*)0x0)->GetClass();
      vectorlEdoublegR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEdoublegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEdoublegR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<double> : new vector<double>;
   }
   static void *newArray_vectorlEdoublegR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<double>[nElements] : new vector<double>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEdoublegR(void *p) {
      delete ((vector<double>*)p);
   }
   static void deleteArray_vectorlEdoublegR(void *p) {
      delete [] ((vector<double>*)p);
   }
   static void destruct_vectorlEdoublegR(void *p) {
      typedef vector<double> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<double>

namespace ROOT {
   static TClass *vectorlETH2DmUgR_Dictionary();
   static void vectorlETH2DmUgR_TClassManip(TClass*);
   static void *new_vectorlETH2DmUgR(void *p = 0);
   static void *newArray_vectorlETH2DmUgR(Long_t size, void *p);
   static void delete_vectorlETH2DmUgR(void *p);
   static void deleteArray_vectorlETH2DmUgR(void *p);
   static void destruct_vectorlETH2DmUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TH2D*>*)
   {
      vector<TH2D*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TH2D*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<TH2D*>", -2, "vector", 216,
                  typeid(vector<TH2D*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlETH2DmUgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<TH2D*>) );
      instance.SetNew(&new_vectorlETH2DmUgR);
      instance.SetNewArray(&newArray_vectorlETH2DmUgR);
      instance.SetDelete(&delete_vectorlETH2DmUgR);
      instance.SetDeleteArray(&deleteArray_vectorlETH2DmUgR);
      instance.SetDestructor(&destruct_vectorlETH2DmUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TH2D*> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<TH2D*>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETH2DmUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<TH2D*>*)0x0)->GetClass();
      vectorlETH2DmUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETH2DmUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETH2DmUgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TH2D*> : new vector<TH2D*>;
   }
   static void *newArray_vectorlETH2DmUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TH2D*>[nElements] : new vector<TH2D*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETH2DmUgR(void *p) {
      delete ((vector<TH2D*>*)p);
   }
   static void deleteArray_vectorlETH2DmUgR(void *p) {
      delete [] ((vector<TH2D*>*)p);
   }
   static void destruct_vectorlETH2DmUgR(void *p) {
      typedef vector<TH2D*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<TH2D*>

namespace ROOT {
   static TClass *maplEstringcOvectorlEvectorlEdoublegRsPgRsPgR_Dictionary();
   static void maplEstringcOvectorlEvectorlEdoublegRsPgRsPgR_TClassManip(TClass*);
   static void *new_maplEstringcOvectorlEvectorlEdoublegRsPgRsPgR(void *p = 0);
   static void *newArray_maplEstringcOvectorlEvectorlEdoublegRsPgRsPgR(Long_t size, void *p);
   static void delete_maplEstringcOvectorlEvectorlEdoublegRsPgRsPgR(void *p);
   static void deleteArray_maplEstringcOvectorlEvectorlEdoublegRsPgRsPgR(void *p);
   static void destruct_maplEstringcOvectorlEvectorlEdoublegRsPgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<string,vector<vector<double> > >*)
   {
      map<string,vector<vector<double> > > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<string,vector<vector<double> > >));
      static ::ROOT::TGenericClassInfo 
         instance("map<string,vector<vector<double> > >", -2, "map", 99,
                  typeid(map<string,vector<vector<double> > >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEstringcOvectorlEvectorlEdoublegRsPgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(map<string,vector<vector<double> > >) );
      instance.SetNew(&new_maplEstringcOvectorlEvectorlEdoublegRsPgRsPgR);
      instance.SetNewArray(&newArray_maplEstringcOvectorlEvectorlEdoublegRsPgRsPgR);
      instance.SetDelete(&delete_maplEstringcOvectorlEvectorlEdoublegRsPgRsPgR);
      instance.SetDeleteArray(&deleteArray_maplEstringcOvectorlEvectorlEdoublegRsPgRsPgR);
      instance.SetDestructor(&destruct_maplEstringcOvectorlEvectorlEdoublegRsPgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<string,vector<vector<double> > > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const map<string,vector<vector<double> > >*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEstringcOvectorlEvectorlEdoublegRsPgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<string,vector<vector<double> > >*)0x0)->GetClass();
      maplEstringcOvectorlEvectorlEdoublegRsPgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEstringcOvectorlEvectorlEdoublegRsPgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEstringcOvectorlEvectorlEdoublegRsPgRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<string,vector<vector<double> > > : new map<string,vector<vector<double> > >;
   }
   static void *newArray_maplEstringcOvectorlEvectorlEdoublegRsPgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<string,vector<vector<double> > >[nElements] : new map<string,vector<vector<double> > >[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEstringcOvectorlEvectorlEdoublegRsPgRsPgR(void *p) {
      delete ((map<string,vector<vector<double> > >*)p);
   }
   static void deleteArray_maplEstringcOvectorlEvectorlEdoublegRsPgRsPgR(void *p) {
      delete [] ((map<string,vector<vector<double> > >*)p);
   }
   static void destruct_maplEstringcOvectorlEvectorlEdoublegRsPgRsPgR(void *p) {
      typedef map<string,vector<vector<double> > > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<string,vector<vector<double> > >

namespace ROOT {
   static TClass *maplEstringcOvectorlEvectorlETH2DmUgRsPgRsPgR_Dictionary();
   static void maplEstringcOvectorlEvectorlETH2DmUgRsPgRsPgR_TClassManip(TClass*);
   static void *new_maplEstringcOvectorlEvectorlETH2DmUgRsPgRsPgR(void *p = 0);
   static void *newArray_maplEstringcOvectorlEvectorlETH2DmUgRsPgRsPgR(Long_t size, void *p);
   static void delete_maplEstringcOvectorlEvectorlETH2DmUgRsPgRsPgR(void *p);
   static void deleteArray_maplEstringcOvectorlEvectorlETH2DmUgRsPgRsPgR(void *p);
   static void destruct_maplEstringcOvectorlEvectorlETH2DmUgRsPgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<string,vector<vector<TH2D*> > >*)
   {
      map<string,vector<vector<TH2D*> > > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<string,vector<vector<TH2D*> > >));
      static ::ROOT::TGenericClassInfo 
         instance("map<string,vector<vector<TH2D*> > >", -2, "map", 99,
                  typeid(map<string,vector<vector<TH2D*> > >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEstringcOvectorlEvectorlETH2DmUgRsPgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(map<string,vector<vector<TH2D*> > >) );
      instance.SetNew(&new_maplEstringcOvectorlEvectorlETH2DmUgRsPgRsPgR);
      instance.SetNewArray(&newArray_maplEstringcOvectorlEvectorlETH2DmUgRsPgRsPgR);
      instance.SetDelete(&delete_maplEstringcOvectorlEvectorlETH2DmUgRsPgRsPgR);
      instance.SetDeleteArray(&deleteArray_maplEstringcOvectorlEvectorlETH2DmUgRsPgRsPgR);
      instance.SetDestructor(&destruct_maplEstringcOvectorlEvectorlETH2DmUgRsPgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<string,vector<vector<TH2D*> > > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const map<string,vector<vector<TH2D*> > >*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEstringcOvectorlEvectorlETH2DmUgRsPgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<string,vector<vector<TH2D*> > >*)0x0)->GetClass();
      maplEstringcOvectorlEvectorlETH2DmUgRsPgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEstringcOvectorlEvectorlETH2DmUgRsPgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEstringcOvectorlEvectorlETH2DmUgRsPgRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<string,vector<vector<TH2D*> > > : new map<string,vector<vector<TH2D*> > >;
   }
   static void *newArray_maplEstringcOvectorlEvectorlETH2DmUgRsPgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<string,vector<vector<TH2D*> > >[nElements] : new map<string,vector<vector<TH2D*> > >[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEstringcOvectorlEvectorlETH2DmUgRsPgRsPgR(void *p) {
      delete ((map<string,vector<vector<TH2D*> > >*)p);
   }
   static void deleteArray_maplEstringcOvectorlEvectorlETH2DmUgRsPgRsPgR(void *p) {
      delete [] ((map<string,vector<vector<TH2D*> > >*)p);
   }
   static void destruct_maplEstringcOvectorlEvectorlETH2DmUgRsPgRsPgR(void *p) {
      typedef map<string,vector<vector<TH2D*> > > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<string,vector<vector<TH2D*> > >

namespace ROOT {
   static TClass *maplEstringcOmaplEstringcOTH2DmUgRsPgR_Dictionary();
   static void maplEstringcOmaplEstringcOTH2DmUgRsPgR_TClassManip(TClass*);
   static void *new_maplEstringcOmaplEstringcOTH2DmUgRsPgR(void *p = 0);
   static void *newArray_maplEstringcOmaplEstringcOTH2DmUgRsPgR(Long_t size, void *p);
   static void delete_maplEstringcOmaplEstringcOTH2DmUgRsPgR(void *p);
   static void deleteArray_maplEstringcOmaplEstringcOTH2DmUgRsPgR(void *p);
   static void destruct_maplEstringcOmaplEstringcOTH2DmUgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<string,map<string,TH2D*> >*)
   {
      map<string,map<string,TH2D*> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<string,map<string,TH2D*> >));
      static ::ROOT::TGenericClassInfo 
         instance("map<string,map<string,TH2D*> >", -2, "map", 99,
                  typeid(map<string,map<string,TH2D*> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEstringcOmaplEstringcOTH2DmUgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(map<string,map<string,TH2D*> >) );
      instance.SetNew(&new_maplEstringcOmaplEstringcOTH2DmUgRsPgR);
      instance.SetNewArray(&newArray_maplEstringcOmaplEstringcOTH2DmUgRsPgR);
      instance.SetDelete(&delete_maplEstringcOmaplEstringcOTH2DmUgRsPgR);
      instance.SetDeleteArray(&deleteArray_maplEstringcOmaplEstringcOTH2DmUgRsPgR);
      instance.SetDestructor(&destruct_maplEstringcOmaplEstringcOTH2DmUgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<string,map<string,TH2D*> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const map<string,map<string,TH2D*> >*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEstringcOmaplEstringcOTH2DmUgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<string,map<string,TH2D*> >*)0x0)->GetClass();
      maplEstringcOmaplEstringcOTH2DmUgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEstringcOmaplEstringcOTH2DmUgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEstringcOmaplEstringcOTH2DmUgRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<string,map<string,TH2D*> > : new map<string,map<string,TH2D*> >;
   }
   static void *newArray_maplEstringcOmaplEstringcOTH2DmUgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<string,map<string,TH2D*> >[nElements] : new map<string,map<string,TH2D*> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEstringcOmaplEstringcOTH2DmUgRsPgR(void *p) {
      delete ((map<string,map<string,TH2D*> >*)p);
   }
   static void deleteArray_maplEstringcOmaplEstringcOTH2DmUgRsPgR(void *p) {
      delete [] ((map<string,map<string,TH2D*> >*)p);
   }
   static void destruct_maplEstringcOmaplEstringcOTH2DmUgRsPgR(void *p) {
      typedef map<string,map<string,TH2D*> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<string,map<string,TH2D*> >

namespace ROOT {
   static TClass *maplEstringcOmaplEstringcOTH1DmUgRsPgR_Dictionary();
   static void maplEstringcOmaplEstringcOTH1DmUgRsPgR_TClassManip(TClass*);
   static void *new_maplEstringcOmaplEstringcOTH1DmUgRsPgR(void *p = 0);
   static void *newArray_maplEstringcOmaplEstringcOTH1DmUgRsPgR(Long_t size, void *p);
   static void delete_maplEstringcOmaplEstringcOTH1DmUgRsPgR(void *p);
   static void deleteArray_maplEstringcOmaplEstringcOTH1DmUgRsPgR(void *p);
   static void destruct_maplEstringcOmaplEstringcOTH1DmUgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<string,map<string,TH1D*> >*)
   {
      map<string,map<string,TH1D*> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<string,map<string,TH1D*> >));
      static ::ROOT::TGenericClassInfo 
         instance("map<string,map<string,TH1D*> >", -2, "map", 99,
                  typeid(map<string,map<string,TH1D*> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEstringcOmaplEstringcOTH1DmUgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(map<string,map<string,TH1D*> >) );
      instance.SetNew(&new_maplEstringcOmaplEstringcOTH1DmUgRsPgR);
      instance.SetNewArray(&newArray_maplEstringcOmaplEstringcOTH1DmUgRsPgR);
      instance.SetDelete(&delete_maplEstringcOmaplEstringcOTH1DmUgRsPgR);
      instance.SetDeleteArray(&deleteArray_maplEstringcOmaplEstringcOTH1DmUgRsPgR);
      instance.SetDestructor(&destruct_maplEstringcOmaplEstringcOTH1DmUgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<string,map<string,TH1D*> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const map<string,map<string,TH1D*> >*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEstringcOmaplEstringcOTH1DmUgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<string,map<string,TH1D*> >*)0x0)->GetClass();
      maplEstringcOmaplEstringcOTH1DmUgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEstringcOmaplEstringcOTH1DmUgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEstringcOmaplEstringcOTH1DmUgRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<string,map<string,TH1D*> > : new map<string,map<string,TH1D*> >;
   }
   static void *newArray_maplEstringcOmaplEstringcOTH1DmUgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<string,map<string,TH1D*> >[nElements] : new map<string,map<string,TH1D*> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEstringcOmaplEstringcOTH1DmUgRsPgR(void *p) {
      delete ((map<string,map<string,TH1D*> >*)p);
   }
   static void deleteArray_maplEstringcOmaplEstringcOTH1DmUgRsPgR(void *p) {
      delete [] ((map<string,map<string,TH1D*> >*)p);
   }
   static void destruct_maplEstringcOmaplEstringcOTH1DmUgRsPgR(void *p) {
      typedef map<string,map<string,TH1D*> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<string,map<string,TH1D*> >

namespace ROOT {
   static TClass *maplEstringcOTH2DmUgR_Dictionary();
   static void maplEstringcOTH2DmUgR_TClassManip(TClass*);
   static void *new_maplEstringcOTH2DmUgR(void *p = 0);
   static void *newArray_maplEstringcOTH2DmUgR(Long_t size, void *p);
   static void delete_maplEstringcOTH2DmUgR(void *p);
   static void deleteArray_maplEstringcOTH2DmUgR(void *p);
   static void destruct_maplEstringcOTH2DmUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<string,TH2D*>*)
   {
      map<string,TH2D*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<string,TH2D*>));
      static ::ROOT::TGenericClassInfo 
         instance("map<string,TH2D*>", -2, "map", 99,
                  typeid(map<string,TH2D*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEstringcOTH2DmUgR_Dictionary, isa_proxy, 4,
                  sizeof(map<string,TH2D*>) );
      instance.SetNew(&new_maplEstringcOTH2DmUgR);
      instance.SetNewArray(&newArray_maplEstringcOTH2DmUgR);
      instance.SetDelete(&delete_maplEstringcOTH2DmUgR);
      instance.SetDeleteArray(&deleteArray_maplEstringcOTH2DmUgR);
      instance.SetDestructor(&destruct_maplEstringcOTH2DmUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<string,TH2D*> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const map<string,TH2D*>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEstringcOTH2DmUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<string,TH2D*>*)0x0)->GetClass();
      maplEstringcOTH2DmUgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEstringcOTH2DmUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEstringcOTH2DmUgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<string,TH2D*> : new map<string,TH2D*>;
   }
   static void *newArray_maplEstringcOTH2DmUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<string,TH2D*>[nElements] : new map<string,TH2D*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEstringcOTH2DmUgR(void *p) {
      delete ((map<string,TH2D*>*)p);
   }
   static void deleteArray_maplEstringcOTH2DmUgR(void *p) {
      delete [] ((map<string,TH2D*>*)p);
   }
   static void destruct_maplEstringcOTH2DmUgR(void *p) {
      typedef map<string,TH2D*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<string,TH2D*>

namespace ROOT {
   static TClass *maplEstringcOTH1DgR_Dictionary();
   static void maplEstringcOTH1DgR_TClassManip(TClass*);
   static void *new_maplEstringcOTH1DgR(void *p = 0);
   static void *newArray_maplEstringcOTH1DgR(Long_t size, void *p);
   static void delete_maplEstringcOTH1DgR(void *p);
   static void deleteArray_maplEstringcOTH1DgR(void *p);
   static void destruct_maplEstringcOTH1DgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<string,TH1D>*)
   {
      map<string,TH1D> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<string,TH1D>));
      static ::ROOT::TGenericClassInfo 
         instance("map<string,TH1D>", -2, "map", 99,
                  typeid(map<string,TH1D>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEstringcOTH1DgR_Dictionary, isa_proxy, 4,
                  sizeof(map<string,TH1D>) );
      instance.SetNew(&new_maplEstringcOTH1DgR);
      instance.SetNewArray(&newArray_maplEstringcOTH1DgR);
      instance.SetDelete(&delete_maplEstringcOTH1DgR);
      instance.SetDeleteArray(&deleteArray_maplEstringcOTH1DgR);
      instance.SetDestructor(&destruct_maplEstringcOTH1DgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<string,TH1D> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const map<string,TH1D>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEstringcOTH1DgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<string,TH1D>*)0x0)->GetClass();
      maplEstringcOTH1DgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEstringcOTH1DgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEstringcOTH1DgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<string,TH1D> : new map<string,TH1D>;
   }
   static void *newArray_maplEstringcOTH1DgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<string,TH1D>[nElements] : new map<string,TH1D>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEstringcOTH1DgR(void *p) {
      delete ((map<string,TH1D>*)p);
   }
   static void deleteArray_maplEstringcOTH1DgR(void *p) {
      delete [] ((map<string,TH1D>*)p);
   }
   static void destruct_maplEstringcOTH1DgR(void *p) {
      typedef map<string,TH1D> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<string,TH1D>

namespace ROOT {
   static TClass *maplEstringcOTH1DmUgR_Dictionary();
   static void maplEstringcOTH1DmUgR_TClassManip(TClass*);
   static void *new_maplEstringcOTH1DmUgR(void *p = 0);
   static void *newArray_maplEstringcOTH1DmUgR(Long_t size, void *p);
   static void delete_maplEstringcOTH1DmUgR(void *p);
   static void deleteArray_maplEstringcOTH1DmUgR(void *p);
   static void destruct_maplEstringcOTH1DmUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<string,TH1D*>*)
   {
      map<string,TH1D*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<string,TH1D*>));
      static ::ROOT::TGenericClassInfo 
         instance("map<string,TH1D*>", -2, "map", 99,
                  typeid(map<string,TH1D*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEstringcOTH1DmUgR_Dictionary, isa_proxy, 4,
                  sizeof(map<string,TH1D*>) );
      instance.SetNew(&new_maplEstringcOTH1DmUgR);
      instance.SetNewArray(&newArray_maplEstringcOTH1DmUgR);
      instance.SetDelete(&delete_maplEstringcOTH1DmUgR);
      instance.SetDeleteArray(&deleteArray_maplEstringcOTH1DmUgR);
      instance.SetDestructor(&destruct_maplEstringcOTH1DmUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<string,TH1D*> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const map<string,TH1D*>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEstringcOTH1DmUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<string,TH1D*>*)0x0)->GetClass();
      maplEstringcOTH1DmUgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEstringcOTH1DmUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEstringcOTH1DmUgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<string,TH1D*> : new map<string,TH1D*>;
   }
   static void *newArray_maplEstringcOTH1DmUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<string,TH1D*>[nElements] : new map<string,TH1D*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEstringcOTH1DmUgR(void *p) {
      delete ((map<string,TH1D*>*)p);
   }
   static void deleteArray_maplEstringcOTH1DmUgR(void *p) {
      delete [] ((map<string,TH1D*>*)p);
   }
   static void destruct_maplEstringcOTH1DmUgR(void *p) {
      typedef map<string,TH1D*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<string,TH1D*>

namespace {
  void TriggerDictionaryInitialization_libLiteFMWK_Main_Impl() {
    static const char* headers[] = {
"GENIEEventHisto.h",
"Maker.h",
"TArray2D.h",
"TArray3D.h",
"sample.h",
0
    };
    static const char* includePaths[] = {
"/cvmfs/larsoft.opensciencegrid.org/products/root/v6_16_00/Linux64bit+2.6-2.12-e17-prof/include",
"/genie/app/jiangl/lamp-new/EScattering/LiteFMWK/Main/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libLiteFMWK_Main dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace std{template <class _CharT> struct __attribute__((annotate("$clingAutoload$bits/char_traits.h")))  __attribute__((annotate("$clingAutoload$string")))  char_traits;
}
namespace std{template <typename > class __attribute__((annotate("$clingAutoload$bits/memoryfwd.h")))  __attribute__((annotate("$clingAutoload$string")))  allocator;
}
class __attribute__((annotate("$clingAutoload$TH2.h")))  __attribute__((annotate("$clingAutoload$Maker.h")))  TH2D;
namespace Main{class __attribute__((annotate("$clingAutoload$Maker.h")))  Maker;}
namespace Main{class __attribute__((annotate("$clingAutoload$sample.h")))  sample;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libLiteFMWK_Main dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "GENIEEventHisto.h"
#include "Maker.h"
#include "TArray2D.h"
#include "TArray3D.h"
#include "sample.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"Main::Maker", payloadCode, "@",
"Main::sample", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libLiteFMWK_Main",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libLiteFMWK_Main_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libLiteFMWK_Main_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libLiteFMWK_Main() {
  TriggerDictionaryInitialization_libLiteFMWK_Main_Impl();
}
