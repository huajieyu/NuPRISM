// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIgeniedIappdIjiangldIlampmInewdIEScatteringdILiteFMWKdIbuilddIBasedIBaseDict

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
#include "CDetectorEffects.h"
#include "CGaussianDistrib.h"
#include "CRandomGen.h"
#include "DUNEAnalogger.h"
#include "DUNENDEventHisto1D.h"
#include "MigrationMatrixCalc.h"
#include "Types.h"
#include "sample.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *BasecLcLCRandomGen_Dictionary();
   static void BasecLcLCRandomGen_TClassManip(TClass*);
   static void *new_BasecLcLCRandomGen(void *p = 0);
   static void *newArray_BasecLcLCRandomGen(Long_t size, void *p);
   static void delete_BasecLcLCRandomGen(void *p);
   static void deleteArray_BasecLcLCRandomGen(void *p);
   static void destruct_BasecLcLCRandomGen(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Base::CRandomGen*)
   {
      ::Base::CRandomGen *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Base::CRandomGen));
      static ::ROOT::TGenericClassInfo 
         instance("Base::CRandomGen", "CRandomGen.h", 29,
                  typeid(::Base::CRandomGen), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &BasecLcLCRandomGen_Dictionary, isa_proxy, 4,
                  sizeof(::Base::CRandomGen) );
      instance.SetNew(&new_BasecLcLCRandomGen);
      instance.SetNewArray(&newArray_BasecLcLCRandomGen);
      instance.SetDelete(&delete_BasecLcLCRandomGen);
      instance.SetDeleteArray(&deleteArray_BasecLcLCRandomGen);
      instance.SetDestructor(&destruct_BasecLcLCRandomGen);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Base::CRandomGen*)
   {
      return GenerateInitInstanceLocal((::Base::CRandomGen*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::Base::CRandomGen*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *BasecLcLCRandomGen_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Base::CRandomGen*)0x0)->GetClass();
      BasecLcLCRandomGen_TClassManip(theClass);
   return theClass;
   }

   static void BasecLcLCRandomGen_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *BasecLcLCGaussianDistrib_Dictionary();
   static void BasecLcLCGaussianDistrib_TClassManip(TClass*);
   static void delete_BasecLcLCGaussianDistrib(void *p);
   static void deleteArray_BasecLcLCGaussianDistrib(void *p);
   static void destruct_BasecLcLCGaussianDistrib(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Base::CGaussianDistrib*)
   {
      ::Base::CGaussianDistrib *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Base::CGaussianDistrib));
      static ::ROOT::TGenericClassInfo 
         instance("Base::CGaussianDistrib", "CGaussianDistrib.h", 28,
                  typeid(::Base::CGaussianDistrib), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &BasecLcLCGaussianDistrib_Dictionary, isa_proxy, 4,
                  sizeof(::Base::CGaussianDistrib) );
      instance.SetDelete(&delete_BasecLcLCGaussianDistrib);
      instance.SetDeleteArray(&deleteArray_BasecLcLCGaussianDistrib);
      instance.SetDestructor(&destruct_BasecLcLCGaussianDistrib);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Base::CGaussianDistrib*)
   {
      return GenerateInitInstanceLocal((::Base::CGaussianDistrib*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::Base::CGaussianDistrib*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *BasecLcLCGaussianDistrib_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Base::CGaussianDistrib*)0x0)->GetClass();
      BasecLcLCGaussianDistrib_TClassManip(theClass);
   return theClass;
   }

   static void BasecLcLCGaussianDistrib_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *BasecLcLCDetectorEffects_Dictionary();
   static void BasecLcLCDetectorEffects_TClassManip(TClass*);
   static void *new_BasecLcLCDetectorEffects(void *p = 0);
   static void *newArray_BasecLcLCDetectorEffects(Long_t size, void *p);
   static void delete_BasecLcLCDetectorEffects(void *p);
   static void deleteArray_BasecLcLCDetectorEffects(void *p);
   static void destruct_BasecLcLCDetectorEffects(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Base::CDetectorEffects*)
   {
      ::Base::CDetectorEffects *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Base::CDetectorEffects));
      static ::ROOT::TGenericClassInfo 
         instance("Base::CDetectorEffects", "CDetectorEffects.h", 28,
                  typeid(::Base::CDetectorEffects), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &BasecLcLCDetectorEffects_Dictionary, isa_proxy, 4,
                  sizeof(::Base::CDetectorEffects) );
      instance.SetNew(&new_BasecLcLCDetectorEffects);
      instance.SetNewArray(&newArray_BasecLcLCDetectorEffects);
      instance.SetDelete(&delete_BasecLcLCDetectorEffects);
      instance.SetDeleteArray(&deleteArray_BasecLcLCDetectorEffects);
      instance.SetDestructor(&destruct_BasecLcLCDetectorEffects);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Base::CDetectorEffects*)
   {
      return GenerateInitInstanceLocal((::Base::CDetectorEffects*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::Base::CDetectorEffects*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *BasecLcLCDetectorEffects_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Base::CDetectorEffects*)0x0)->GetClass();
      BasecLcLCDetectorEffects_TClassManip(theClass);
   return theClass;
   }

   static void BasecLcLCDetectorEffects_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *BasecLcLDUNENDEventHisto1D_Dictionary();
   static void BasecLcLDUNENDEventHisto1D_TClassManip(TClass*);
   static void *new_BasecLcLDUNENDEventHisto1D(void *p = 0);
   static void *newArray_BasecLcLDUNENDEventHisto1D(Long_t size, void *p);
   static void delete_BasecLcLDUNENDEventHisto1D(void *p);
   static void deleteArray_BasecLcLDUNENDEventHisto1D(void *p);
   static void destruct_BasecLcLDUNENDEventHisto1D(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Base::DUNENDEventHisto1D*)
   {
      ::Base::DUNENDEventHisto1D *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Base::DUNENDEventHisto1D));
      static ::ROOT::TGenericClassInfo 
         instance("Base::DUNENDEventHisto1D", "DUNENDEventHisto1D.h", 53,
                  typeid(::Base::DUNENDEventHisto1D), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &BasecLcLDUNENDEventHisto1D_Dictionary, isa_proxy, 4,
                  sizeof(::Base::DUNENDEventHisto1D) );
      instance.SetNew(&new_BasecLcLDUNENDEventHisto1D);
      instance.SetNewArray(&newArray_BasecLcLDUNENDEventHisto1D);
      instance.SetDelete(&delete_BasecLcLDUNENDEventHisto1D);
      instance.SetDeleteArray(&deleteArray_BasecLcLDUNENDEventHisto1D);
      instance.SetDestructor(&destruct_BasecLcLDUNENDEventHisto1D);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Base::DUNENDEventHisto1D*)
   {
      return GenerateInitInstanceLocal((::Base::DUNENDEventHisto1D*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::Base::DUNENDEventHisto1D*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *BasecLcLDUNENDEventHisto1D_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Base::DUNENDEventHisto1D*)0x0)->GetClass();
      BasecLcLDUNENDEventHisto1D_TClassManip(theClass);
   return theClass;
   }

   static void BasecLcLDUNENDEventHisto1D_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *BasecLcLMigrationMatrixCalc_Dictionary();
   static void BasecLcLMigrationMatrixCalc_TClassManip(TClass*);
   static void *new_BasecLcLMigrationMatrixCalc(void *p = 0);
   static void *newArray_BasecLcLMigrationMatrixCalc(Long_t size, void *p);
   static void delete_BasecLcLMigrationMatrixCalc(void *p);
   static void deleteArray_BasecLcLMigrationMatrixCalc(void *p);
   static void destruct_BasecLcLMigrationMatrixCalc(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Base::MigrationMatrixCalc*)
   {
      ::Base::MigrationMatrixCalc *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Base::MigrationMatrixCalc));
      static ::ROOT::TGenericClassInfo 
         instance("Base::MigrationMatrixCalc", "MigrationMatrixCalc.h", 68,
                  typeid(::Base::MigrationMatrixCalc), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &BasecLcLMigrationMatrixCalc_Dictionary, isa_proxy, 4,
                  sizeof(::Base::MigrationMatrixCalc) );
      instance.SetNew(&new_BasecLcLMigrationMatrixCalc);
      instance.SetNewArray(&newArray_BasecLcLMigrationMatrixCalc);
      instance.SetDelete(&delete_BasecLcLMigrationMatrixCalc);
      instance.SetDeleteArray(&deleteArray_BasecLcLMigrationMatrixCalc);
      instance.SetDestructor(&destruct_BasecLcLMigrationMatrixCalc);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Base::MigrationMatrixCalc*)
   {
      return GenerateInitInstanceLocal((::Base::MigrationMatrixCalc*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::Base::MigrationMatrixCalc*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *BasecLcLMigrationMatrixCalc_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Base::MigrationMatrixCalc*)0x0)->GetClass();
      BasecLcLMigrationMatrixCalc_TClassManip(theClass);
   return theClass;
   }

   static void BasecLcLMigrationMatrixCalc_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *BasecLcLsample_Dictionary();
   static void BasecLcLsample_TClassManip(TClass*);
   static void *new_BasecLcLsample(void *p = 0);
   static void *newArray_BasecLcLsample(Long_t size, void *p);
   static void delete_BasecLcLsample(void *p);
   static void deleteArray_BasecLcLsample(void *p);
   static void destruct_BasecLcLsample(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Base::sample*)
   {
      ::Base::sample *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Base::sample));
      static ::ROOT::TGenericClassInfo 
         instance("Base::sample", "sample.h", 24,
                  typeid(::Base::sample), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &BasecLcLsample_Dictionary, isa_proxy, 4,
                  sizeof(::Base::sample) );
      instance.SetNew(&new_BasecLcLsample);
      instance.SetNewArray(&newArray_BasecLcLsample);
      instance.SetDelete(&delete_BasecLcLsample);
      instance.SetDeleteArray(&deleteArray_BasecLcLsample);
      instance.SetDestructor(&destruct_BasecLcLsample);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Base::sample*)
   {
      return GenerateInitInstanceLocal((::Base::sample*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::Base::sample*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *BasecLcLsample_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Base::sample*)0x0)->GetClass();
      BasecLcLsample_TClassManip(theClass);
   return theClass;
   }

   static void BasecLcLsample_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_BasecLcLCRandomGen(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::Base::CRandomGen : new ::Base::CRandomGen;
   }
   static void *newArray_BasecLcLCRandomGen(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::Base::CRandomGen[nElements] : new ::Base::CRandomGen[nElements];
   }
   // Wrapper around operator delete
   static void delete_BasecLcLCRandomGen(void *p) {
      delete ((::Base::CRandomGen*)p);
   }
   static void deleteArray_BasecLcLCRandomGen(void *p) {
      delete [] ((::Base::CRandomGen*)p);
   }
   static void destruct_BasecLcLCRandomGen(void *p) {
      typedef ::Base::CRandomGen current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Base::CRandomGen

namespace ROOT {
   // Wrapper around operator delete
   static void delete_BasecLcLCGaussianDistrib(void *p) {
      delete ((::Base::CGaussianDistrib*)p);
   }
   static void deleteArray_BasecLcLCGaussianDistrib(void *p) {
      delete [] ((::Base::CGaussianDistrib*)p);
   }
   static void destruct_BasecLcLCGaussianDistrib(void *p) {
      typedef ::Base::CGaussianDistrib current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Base::CGaussianDistrib

namespace ROOT {
   // Wrappers around operator new
   static void *new_BasecLcLCDetectorEffects(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::Base::CDetectorEffects : new ::Base::CDetectorEffects;
   }
   static void *newArray_BasecLcLCDetectorEffects(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::Base::CDetectorEffects[nElements] : new ::Base::CDetectorEffects[nElements];
   }
   // Wrapper around operator delete
   static void delete_BasecLcLCDetectorEffects(void *p) {
      delete ((::Base::CDetectorEffects*)p);
   }
   static void deleteArray_BasecLcLCDetectorEffects(void *p) {
      delete [] ((::Base::CDetectorEffects*)p);
   }
   static void destruct_BasecLcLCDetectorEffects(void *p) {
      typedef ::Base::CDetectorEffects current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Base::CDetectorEffects

namespace ROOT {
   // Wrappers around operator new
   static void *new_BasecLcLDUNENDEventHisto1D(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::Base::DUNENDEventHisto1D : new ::Base::DUNENDEventHisto1D;
   }
   static void *newArray_BasecLcLDUNENDEventHisto1D(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::Base::DUNENDEventHisto1D[nElements] : new ::Base::DUNENDEventHisto1D[nElements];
   }
   // Wrapper around operator delete
   static void delete_BasecLcLDUNENDEventHisto1D(void *p) {
      delete ((::Base::DUNENDEventHisto1D*)p);
   }
   static void deleteArray_BasecLcLDUNENDEventHisto1D(void *p) {
      delete [] ((::Base::DUNENDEventHisto1D*)p);
   }
   static void destruct_BasecLcLDUNENDEventHisto1D(void *p) {
      typedef ::Base::DUNENDEventHisto1D current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Base::DUNENDEventHisto1D

namespace ROOT {
   // Wrappers around operator new
   static void *new_BasecLcLMigrationMatrixCalc(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::Base::MigrationMatrixCalc : new ::Base::MigrationMatrixCalc;
   }
   static void *newArray_BasecLcLMigrationMatrixCalc(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::Base::MigrationMatrixCalc[nElements] : new ::Base::MigrationMatrixCalc[nElements];
   }
   // Wrapper around operator delete
   static void delete_BasecLcLMigrationMatrixCalc(void *p) {
      delete ((::Base::MigrationMatrixCalc*)p);
   }
   static void deleteArray_BasecLcLMigrationMatrixCalc(void *p) {
      delete [] ((::Base::MigrationMatrixCalc*)p);
   }
   static void destruct_BasecLcLMigrationMatrixCalc(void *p) {
      typedef ::Base::MigrationMatrixCalc current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Base::MigrationMatrixCalc

namespace ROOT {
   // Wrappers around operator new
   static void *new_BasecLcLsample(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::Base::sample : new ::Base::sample;
   }
   static void *newArray_BasecLcLsample(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::Base::sample[nElements] : new ::Base::sample[nElements];
   }
   // Wrapper around operator delete
   static void delete_BasecLcLsample(void *p) {
      delete ((::Base::sample*)p);
   }
   static void deleteArray_BasecLcLsample(void *p) {
      delete [] ((::Base::sample*)p);
   }
   static void destruct_BasecLcLsample(void *p) {
      typedef ::Base::sample current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Base::sample

namespace {
  void TriggerDictionaryInitialization_libLiteFMWK_Base_Impl() {
    static const char* headers[] = {
"CDetectorEffects.h",
"CGaussianDistrib.h",
"CRandomGen.h",
"DUNEAnalogger.h",
"DUNENDEventHisto1D.h",
"MigrationMatrixCalc.h",
"Types.h",
"sample.h",
0
    };
    static const char* includePaths[] = {
"/cvmfs/larsoft.opensciencegrid.org/products/root/v6_16_00/Linux64bit+2.6-2.12-e17-prof/include",
"/genie/app/jiangl/lamp-new/EScattering/LiteFMWK/Base/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libLiteFMWK_Base dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace Base{class __attribute__((annotate("$clingAutoload$CRandomGen.h")))  __attribute__((annotate("$clingAutoload$CDetectorEffects.h")))  CRandomGen;}
namespace Base{class __attribute__((annotate("$clingAutoload$CGaussianDistrib.h")))  __attribute__((annotate("$clingAutoload$CDetectorEffects.h")))  CGaussianDistrib;}
namespace Base{class __attribute__((annotate("$clingAutoload$CDetectorEffects.h")))  CDetectorEffects;}
namespace Base{class __attribute__((annotate("$clingAutoload$DUNENDEventHisto1D.h")))  DUNENDEventHisto1D;}
namespace Base{class __attribute__((annotate("$clingAutoload$MigrationMatrixCalc.h")))  MigrationMatrixCalc;}
namespace Base{class __attribute__((annotate("$clingAutoload$sample.h")))  sample;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libLiteFMWK_Base dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "CDetectorEffects.h"
#include "CGaussianDistrib.h"
#include "CRandomGen.h"
#include "DUNEAnalogger.h"
#include "DUNENDEventHisto1D.h"
#include "MigrationMatrixCalc.h"
#include "Types.h"
#include "sample.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"Base::CDetectorEffects", payloadCode, "@",
"Base::CGaussianDistrib", payloadCode, "@",
"Base::CRandomGen", payloadCode, "@",
"Base::DUNENDEventHisto1D", payloadCode, "@",
"Base::MigrationMatrixCalc", payloadCode, "@",
"Base::sample", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libLiteFMWK_Base",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libLiteFMWK_Base_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libLiteFMWK_Base_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libLiteFMWK_Base() {
  TriggerDictionaryInitialization_libLiteFMWK_Base_Impl();
}
