//
// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE.md file in the project root for full license information.
//

#pragma once

#include <chrono>

namespace Microsoft {
namespace CognitiveServices {
namespace Speech {
namespace Impl {

// Data chunk interface.
struct DataChunk
{
    DataChunk(std::shared_ptr<uint8_t> data, uint32_t dataSizeInBytes)
        : data{ data }, size{ dataSizeInBytes }, receivedTime{ std::chrono::system_clock::now() }
    { }

    DataChunk(std::shared_ptr<uint8_t> data, uint32_t dataSizeInBytes, std::chrono::system_clock::time_point chunkTime)
        : data{ data }, size{ dataSizeInBytes }, receivedTime{ chunkTime }
    { }

    std::shared_ptr<uint8_t> data;  // Actual data.
    uint32_t size;                  // Current size of valid data in bytes
    std::chrono::system_clock::time_point receivedTime; // The receive time of audio chunk.
};

using DataChunkPtr = std::shared_ptr<DataChunk>;

}}}}