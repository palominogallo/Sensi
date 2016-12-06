// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME mydict

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
#include "/Users/palominogallo/Work/ptheta/Sensi/include/Asimov.hh"
#include "/Users/palominogallo/Work/ptheta/Sensi/include/SepFit.hh"
#include "/Users/palominogallo/Work/ptheta/Sensi/include/FC.hh"
#include "/Users/palominogallo/Work/ptheta/Sensi/include/SensiUtils.hh"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *Asimov_Dictionary();
   static void Asimov_TClassManip(TClass*);
   static void *new_Asimov(void *p = 0);
   static void *newArray_Asimov(Long_t size, void *p);
   static void delete_Asimov(void *p);
   static void deleteArray_Asimov(void *p);
   static void destruct_Asimov(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Asimov*)
   {
      ::Asimov *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Asimov));
      static ::ROOT::TGenericClassInfo 
         instance("Asimov", "Asimov.hh", 10,
                  typeid(::Asimov), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &Asimov_Dictionary, isa_proxy, 0,
                  sizeof(::Asimov) );
      instance.SetNew(&new_Asimov);
      instance.SetNewArray(&newArray_Asimov);
      instance.SetDelete(&delete_Asimov);
      instance.SetDeleteArray(&deleteArray_Asimov);
      instance.SetDestructor(&destruct_Asimov);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Asimov*)
   {
      return GenerateInitInstanceLocal((::Asimov*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::Asimov*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *Asimov_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Asimov*)0x0)->GetClass();
      Asimov_TClassManip(theClass);
   return theClass;
   }

   static void Asimov_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SepFit_Dictionary();
   static void SepFit_TClassManip(TClass*);
   static void *new_SepFit(void *p = 0);
   static void *newArray_SepFit(Long_t size, void *p);
   static void delete_SepFit(void *p);
   static void deleteArray_SepFit(void *p);
   static void destruct_SepFit(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SepFit*)
   {
      ::SepFit *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SepFit));
      static ::ROOT::TGenericClassInfo 
         instance("SepFit", "SepFit.hh", 10,
                  typeid(::SepFit), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &SepFit_Dictionary, isa_proxy, 0,
                  sizeof(::SepFit) );
      instance.SetNew(&new_SepFit);
      instance.SetNewArray(&newArray_SepFit);
      instance.SetDelete(&delete_SepFit);
      instance.SetDeleteArray(&deleteArray_SepFit);
      instance.SetDestructor(&destruct_SepFit);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SepFit*)
   {
      return GenerateInitInstanceLocal((::SepFit*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SepFit*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SepFit_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SepFit*)0x0)->GetClass();
      SepFit_TClassManip(theClass);
   return theClass;
   }

   static void SepFit_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *FC_Dictionary();
   static void FC_TClassManip(TClass*);
   static void *new_FC(void *p = 0);
   static void *newArray_FC(Long_t size, void *p);
   static void delete_FC(void *p);
   static void deleteArray_FC(void *p);
   static void destruct_FC(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::FC*)
   {
      ::FC *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::FC));
      static ::ROOT::TGenericClassInfo 
         instance("FC", "FC.hh", 10,
                  typeid(::FC), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &FC_Dictionary, isa_proxy, 0,
                  sizeof(::FC) );
      instance.SetNew(&new_FC);
      instance.SetNewArray(&newArray_FC);
      instance.SetDelete(&delete_FC);
      instance.SetDeleteArray(&deleteArray_FC);
      instance.SetDestructor(&destruct_FC);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::FC*)
   {
      return GenerateInitInstanceLocal((::FC*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::FC*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *FC_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::FC*)0x0)->GetClass();
      FC_TClassManip(theClass);
   return theClass;
   }

   static void FC_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SensiUtils_Dictionary();
   static void SensiUtils_TClassManip(TClass*);
   static void *new_SensiUtils(void *p = 0);
   static void *newArray_SensiUtils(Long_t size, void *p);
   static void delete_SensiUtils(void *p);
   static void deleteArray_SensiUtils(void *p);
   static void destruct_SensiUtils(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SensiUtils*)
   {
      ::SensiUtils *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SensiUtils));
      static ::ROOT::TGenericClassInfo 
         instance("SensiUtils", "SensiUtils.hh", 11,
                  typeid(::SensiUtils), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &SensiUtils_Dictionary, isa_proxy, 0,
                  sizeof(::SensiUtils) );
      instance.SetNew(&new_SensiUtils);
      instance.SetNewArray(&newArray_SensiUtils);
      instance.SetDelete(&delete_SensiUtils);
      instance.SetDeleteArray(&deleteArray_SensiUtils);
      instance.SetDestructor(&destruct_SensiUtils);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SensiUtils*)
   {
      return GenerateInitInstanceLocal((::SensiUtils*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SensiUtils*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SensiUtils_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SensiUtils*)0x0)->GetClass();
      SensiUtils_TClassManip(theClass);
   return theClass;
   }

   static void SensiUtils_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_Asimov(void *p) {
      return  p ? new(p) ::Asimov : new ::Asimov;
   }
   static void *newArray_Asimov(Long_t nElements, void *p) {
      return p ? new(p) ::Asimov[nElements] : new ::Asimov[nElements];
   }
   // Wrapper around operator delete
   static void delete_Asimov(void *p) {
      delete ((::Asimov*)p);
   }
   static void deleteArray_Asimov(void *p) {
      delete [] ((::Asimov*)p);
   }
   static void destruct_Asimov(void *p) {
      typedef ::Asimov current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Asimov

namespace ROOT {
   // Wrappers around operator new
   static void *new_SepFit(void *p) {
      return  p ? new(p) ::SepFit : new ::SepFit;
   }
   static void *newArray_SepFit(Long_t nElements, void *p) {
      return p ? new(p) ::SepFit[nElements] : new ::SepFit[nElements];
   }
   // Wrapper around operator delete
   static void delete_SepFit(void *p) {
      delete ((::SepFit*)p);
   }
   static void deleteArray_SepFit(void *p) {
      delete [] ((::SepFit*)p);
   }
   static void destruct_SepFit(void *p) {
      typedef ::SepFit current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SepFit

namespace ROOT {
   // Wrappers around operator new
   static void *new_FC(void *p) {
      return  p ? new(p) ::FC : new ::FC;
   }
   static void *newArray_FC(Long_t nElements, void *p) {
      return p ? new(p) ::FC[nElements] : new ::FC[nElements];
   }
   // Wrapper around operator delete
   static void delete_FC(void *p) {
      delete ((::FC*)p);
   }
   static void deleteArray_FC(void *p) {
      delete [] ((::FC*)p);
   }
   static void destruct_FC(void *p) {
      typedef ::FC current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::FC

namespace ROOT {
   // Wrappers around operator new
   static void *new_SensiUtils(void *p) {
      return  p ? new(p) ::SensiUtils : new ::SensiUtils;
   }
   static void *newArray_SensiUtils(Long_t nElements, void *p) {
      return p ? new(p) ::SensiUtils[nElements] : new ::SensiUtils[nElements];
   }
   // Wrapper around operator delete
   static void delete_SensiUtils(void *p) {
      delete ((::SensiUtils*)p);
   }
   static void deleteArray_SensiUtils(void *p) {
      delete [] ((::SensiUtils*)p);
   }
   static void destruct_SensiUtils(void *p) {
      typedef ::SensiUtils current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SensiUtils

namespace {
  void TriggerDictionaryInitialization_mydict_Impl() {
    static const char* headers[] = {
"/Users/palominogallo/Work/ptheta/Sensi/include/Asimov.hh",
"/Users/palominogallo/Work/ptheta/Sensi/include/SepFit.hh",
"/Users/palominogallo/Work/ptheta/Sensi/include/FC.hh",
"/Users/palominogallo/Work/ptheta/Sensi/include/SensiUtils.hh",
0
    };
    static const char* includePaths[] = {
"/Users/palominogallo/root-v6-07-06/include",
"/Users/palominogallo/Work/ptheta/Sensi/include",
"/Users/palominogallo/Work/JoyRoot//include",
"/Users/palominogallo/root-v6-07-06/include",
"/Users/palominogallo/Work/ptheta/Sensi/src/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "mydict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$/Users/palominogallo/Work/ptheta/Sensi/include/Asimov.hh")))  Asimov;
class __attribute__((annotate("$clingAutoload$/Users/palominogallo/Work/ptheta/Sensi/include/SepFit.hh")))  SepFit;
class __attribute__((annotate("$clingAutoload$/Users/palominogallo/Work/ptheta/Sensi/include/FC.hh")))  FC;
class __attribute__((annotate("$clingAutoload$/Users/palominogallo/Work/ptheta/Sensi/include/SensiUtils.hh")))  SensiUtils;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "mydict dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "/Users/palominogallo/Work/ptheta/Sensi/include/Asimov.hh"
#include "/Users/palominogallo/Work/ptheta/Sensi/include/SepFit.hh"
#include "/Users/palominogallo/Work/ptheta/Sensi/include/FC.hh"
#include "/Users/palominogallo/Work/ptheta/Sensi/include/SensiUtils.hh"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"Asimov", payloadCode, "@",
"FC", payloadCode, "@",
"SensiUtils", payloadCode, "@",
"SepFit", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("mydict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_mydict_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_mydict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_mydict() {
  TriggerDictionaryInitialization_mydict_Impl();
}
