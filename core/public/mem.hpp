/**
 * All rights reserved.
 * License: see LICENSE.txt
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must display the names 'Denis Zyamaev' and
 * in the credits of the application, if such credits exist.
 * The authors of this work must be notified via email (code4un@yandex.ru) in
 * this case of redistribution.
 * 3. Neither the name of copyright holders nor the names of its contributors
 * may be used to endorse or promote products derived from this software
 * without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS
 * IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 **/

#if defined(__cpluplus) && __cpluplus >= 201103L
#pragma once
#endif

#ifndef MEM_HPP
#define MEM_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// ===========================================================
// API
// ===========================================================

#if defined( MEM_SHARED ) // Shared

// Export
#if defined( MEM_EXPORT )

#define MEM_API __declspec( dllexport )

#else

// Import
#define MEM_API __declspec( dllimport )

#endif // MEM_EXPORT
#elif defined( MEM_STATIC ) // Static
#define MEM_API
#else
#define MEM_API
#endif // Shared

// ===========================================================
// TYPES
// ===========================================================

namespace mem
{

    // -----------------------------------------------------------

    class MEM_API MemoryEngine final
    {

        private:

            // -----------------------------------------------------------

            // ===========================================================
            // CONSTRUCTOR
            // ===========================================================

            explicit MemoryEngine() noexcept;

            // ===========================================================
            // DELETED
            // ===========================================================

            MemoryEngine(const MemoryEngine&) noexcept = delete;
            MemoryEngine( MemoryEngine&&) noexcept = delete;
            MemoryEngine& operator=(const MemoryEngine&) noexcept = delete;
            MemoryEngine& operator=(MemoryEngine&&) noexcept = delete;

            // -----------------------------------------------------------

        public:

            // -----------------------------------------------------------

            // ===========================================================
            // DESTRUCTOR
            // ===========================================================

            ~MemoryEngine() noexcept;

            // -----------------------------------------------------------

    }; /// mem::MemoryEngine

    // -----------------------------------------------------------

}
using mem_Engine = mem::MemoryEngine;

// -----------------------------------------------------------

#endif // !MEM_HPP