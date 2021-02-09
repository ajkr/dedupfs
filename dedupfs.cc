//  Copyright (c) 2021-present, Facebook, Inc.  All rights reserved.
//  This source code is licensed under both the GPLv2 (found in the
//  COPYING file in the root directory) and Apache 2.0 License
//  (found in the LICENSE.Apache file in the root directory).

#include "dedupfs.h"

#include <openssl/md5.h>
#include <rocksdb/utilities/object_registry.h>

namespace ROCKSDB_NAMESPACE {

#ifndef ROCKSDB_LITE

extern "C" FactoryFunc<FileSystem> dedupfs_reg;

FactoryFunc<FileSystem> dedupfs_reg =
    ObjectLibrary::Default()->Register<FileSystem>(
        "dedupfs",
        [](const std::string& /* uri */, std::unique_ptr<FileSystem>* f,
           std::string* /* errmsg */) {
          *f = NewDedupFileSystem();
          return f->get();
        });

#endif  // ROCKSDB_LITE

class DedupFileSystem : public FileSystemWrapper {
 public:
  DedupFileSystem(std::shared_ptr<FileSystem> t) : FileSystemWrapper(t) {}
};

std::unique_ptr<FileSystem>
NewDedupFileSystem() {
  return std::unique_ptr<FileSystem>(
      new DedupFileSystem(FileSystem::Default()));
}

}  // namespace ROCKSDB_NAMESPACE
