#ifndef EXPRESSION_CONCEPTS_H
#define EXPRESSION_CONCEPTS_H

namespace expression_concepts
{
	template<auto left,auto right>
	concept greater = left > right;

	template<auto left, auto right>
	concept greater_equal = left >= right;

	template<auto left, auto right>
	concept less = left < right;

	template<auto left, auto right>
	concept less_equal = left <= right;

	template<auto left, auto right>
	concept equal = left == right;

	template<auto left, auto right>
	concept not_euqal = left != right;

	template<bool value>
	concept proxy = value;

	namespace detail
	{
		template<unsigned int select,unsigned int ... values>
		concept just_impl = (values + ...) == select;

		template<unsigned int select, unsigned int ... values>
		concept atleast_impl = (values + ...) >= select;

		template<unsigned int select, unsigned int ... values>
		concept atmost_impl = (values + ...) <= select;
	}

	template<unsigned int select, bool ... values>
	concept just = detail::just_impl<select, static_cast<unsigned int>(values) ...>;

	template<unsigned int select, bool ... values>
	concept atleast = detail::atleast_impl<select, static_cast<unsigned int>(values) ...>;

	template<unsigned int select, bool ... values>
	concept atmost = detail::atmost_impl<select, static_cast<unsigned int>(values) ...>;

	template<bool ...values>
	concept just_zero = just<0, values ...>;
	
	template<bool ...values>
	concept just_one = just<1, values ...>;
}

#endif