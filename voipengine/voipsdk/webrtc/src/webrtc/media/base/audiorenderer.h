/*
 *  Copyright (c) 2013 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef WEBRTC_MEDIA_BASE_AUDIORENDERER_H_
#define WEBRTC_MEDIA_BASE_AUDIORENDERER_H_

#include <cstddef>

namespace cricket {

// Abstract interface for rendering the audio data.
class AudioRenderer {
 public:
  class Sink {
   public:
    // Callback to receive data from the AudioRenderer.
    virtual void OnData(const void* audio_data,
                        int bits_per_sample,
                        int sample_rate,
                        size_t number_of_channels,
                        size_t number_of_frames) = 0;

    // Called when the AudioRenderer is going away.
    virtual void OnClose() = 0;

   protected:
    virtual ~Sink() {}
  };

  // Sets a sink to the AudioRenderer. There can be only one sink connected
  // to the renderer at a time.
  virtual void SetSink(Sink* sink) {}

 protected:
  virtual ~AudioRenderer() {}
};

}  // namespace cricket

#endif  // WEBRTC_MEDIA_BASE_AUDIORENDERER_H_