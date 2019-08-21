// Copyright 2004-present Facebook. All Rights Reserved.

#pragma once

#include <fb/fbjni.h>

#include <compactdisk-current-jni/JMapEntry.h>

namespace compactdisk_jni { namespace experimental {

template <typename K, typename V>
class JSimpleMapEntry : public facebook::jni::JavaClass<JSimpleMapEntry<K, V>, JMapEntry<K, V>> {
 public:
  static constexpr auto kJavaDescriptor = "Ljava/util/AbstractMap$SimpleEntry;";

  static facebook::jni::local_ref<JSimpleMapEntry> create(
      facebook::jni::alias_ref<K> key,
      facebook::jni::alias_ref<V> value);
};


// -------------------- Template Implementation --------------------

template <typename K, typename V>
facebook::jni::local_ref<JSimpleMapEntry<K, V>> JSimpleMapEntry<K, V>::create(
    facebook::jni::alias_ref<K> key,
    facebook::jni::alias_ref<V> value) {
  static auto jClass = JSimpleMapEntry<K, V>::javaClassStatic();
  static auto jConstructor = jClass->template getConstructor<
      typename JSimpleMapEntry<K, V>::javaobject(jobject, jobject)>();
  return jClass->newObject(
      jConstructor,
      facebook::jni::static_ref_cast<jobject>(key).get(),
      facebook::jni::static_ref_cast<jobject>(value).get());
}

}}
