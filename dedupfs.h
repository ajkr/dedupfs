//  Copyright (c) 2021-present, Facebook, Inc.  All rights reserved.
//  This source code is licensed under both the GPLv2 (found in the
//  COPYING file in the root directory) and Apache 2.0 License
//  (found in the LICENSE.Apache file in the root directory).

#pragma once

#include <rocksdb/file_system.h>

namespace ROCKSDB_NAMESPACE {

// Returns a `FileSystem` that hashes file contents when naming files, thus
// deduping them. RocksDB however expects files to be identified based on a
// monotonically increasing counter, so a mapping of RocksDB's name to content
// hash is needed. This mapping is stored in a separate RocksDB instance.
std::unique_ptr<ROCKSDB_NAMESPACE::FileSystem>
NewDedupFileSystem();

}  // namespace ROCKSDB_NAMESPACE
