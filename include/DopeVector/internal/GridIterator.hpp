// Copyright (c) 2016 Giorgio Marcias & Maurizio Kovacic
//
// This source code is part of DopeVector header library
// and it is subject to Apache 2.0 License.
//
// Author: Giorgio Marcias
// email: marcias.giorgio@gmail.com
// Author: Maurizio Kovacic
// email: maurizio.kovacic@gmail.com

#ifndef GridIterator_hpp
#define GridIterator_hpp

#include <iterator>
#include <DopeVector/Index.hpp>

namespace dope {

	namespace internal {

		template < typename T, SizeType Dimension >
		class GridIterator : public std::iterator<std::random_access_iterator_tag, T> {
		public:
			typedef typename std::iterator<std::random_access_iterator_tag, T> Base;
			typedef Index<Dimension> IndexD;
			typedef GridIterator     self_type;
			typedef typename Base::difference_type difference_type;
			typedef typename Base::pointer pointer;
			typedef typename Base::reference reference;

			inline GridIterator();
			inline GridIterator(pointer ptr, const IndexD &range, const SizeType i);
			inline GridIterator(pointer ptr, const IndexD &range, const IndexD &index);
			inline GridIterator(const self_type &o) = default;
			inline GridIterator(self_type &&o) = default;
			inline ~GridIterator();

			inline SizeType to_position() const;
			inline IndexD   to_index() const;

			inline bool operator==(const self_type &o) const;
			inline bool operator!=(const self_type &o) const;
			inline self_type& operator=(const self_type &o) = default;

			inline reference operator*();
			inline pointer operator->();

			inline self_type& operator++();
			inline self_type operator++(int);

			inline self_type& operator--();
			inline self_type operator--(int);

			inline self_type operator+(const SizeType n) const;
			friend inline self_type operator+(const SizeType n, const self_type &it) ;
			inline self_type operator+(const IndexD &n) const;
			friend inline self_type operator+(const IndexD &n, const self_type &it);
			inline self_type operator-(const SizeType n) const;
			inline self_type operator-(const IndexD &n) const;
			inline difference_type operator-(const self_type &o) const;

			inline bool operator<(const self_type &o) const;
			inline bool operator<=(const self_type &o) const;
			inline bool operator>(const self_type &o) const;
			inline bool operator>=(const self_type &o) const;

			inline self_type& operator+=(const SizeType n);
			inline self_type& operator-=(const SizeType n);

			inline self_type& operator+=(const IndexD &n);
			inline self_type& operator-=(const IndexD &n);

			inline reference operator[](const SizeType n) const;
			inline reference operator[](const IndexD &n) const;

			inline void swap(self_type &o);
			friend inline void swap(self_type &it0, self_type &it1);

		protected:
			pointer  _ptr;
			IndexD   _range;
			SizeType _i;
		};

	}

}

#include <DopeVector/internal/inlines/GridIterator.inl>

#endif // GridIterator_hpp