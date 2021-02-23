#ifndef FLAMESTEELCORE_UNUSED_DEFINED
#define FLAMESTEELCORE_UNUSED_DEFINED

template <typename ...Args>
void unused(Args&& ...args)
{
    (void)(sizeof...(args));
}
#endif
