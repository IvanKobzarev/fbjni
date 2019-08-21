// Copyright 2004-present Facebook. All Rights Reserved.

#pragma once

#include <fb/fbjni.h>

namespace compactdisk_jni { namespace experimental {

template <typename K, typename V>
class JMapEntry : public facebook::jni::JavaClass<JMapEntry<K, V>> {
 public:
  static constexpr auto kJavaDescriptor = "Ljava/util/Map$Entry;";

  facebook::jni::local_ref<typename K::javaobject> getKey() const {
    static auto getKeyMethod =
      JMapEntry<K, V>::javaClassStatic()->template getMethod<typename K::javaobject()>("getKey");
    return getKeyMethod(this->self());
  }

  facebook::jni::local_ref<typename V::javaobject> getValue() const {
    static auto getValueMethod =
      JMapEntry<K, V>::javaClassStatic()->template getMethod<typename V::javaobject()>("getValue");
    return getValueMethod(this->self());
  }
};

}}
