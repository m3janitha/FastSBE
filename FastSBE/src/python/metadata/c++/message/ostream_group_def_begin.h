
template <class CharT, class Traits = std::char_traits<CharT>>
inline std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os
    , const S_NAMESPACE::S_MESSAGE_NAME::S_GROUP_NAME& group)
{
	for (auto i = 0; i < group.get_numInGroup(); i++)
	{
		auto& g = group.get(group, i);

