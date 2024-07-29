namespace battle_net_offsets
{
        uint32_t o_item_base = 0xE56B5A0;
 
        uint32_t o_item_pos = 0x1D0;
        uint32_t o_item_size = 0x338;
        uint32_t o_item_valid_1 = 0xC8;
        uint32_t o_item_valid_2 = o_item_valid_1 + 0x2;
 
        uint32_t o_visible_bit = 0x92818;
        uint32_t o_local_entity = 0x760;
 
        uint32_t o_local_index = 0x101B70;
        uint32_t o_local_index_pos = 0x2F0;
 
        uint32_t o_refdef = 0x1512BE78;
 
        uint32_t o_local_base = 0x159AEBB0;
        uint32_t o_camera_pos = 0x204;
 
        uint32_t o_distribute = 0xD4ADAB8;
        uint32_t o_visible = 0x2CFB880;
        uint32_t o_visible_offset = 0xA88;
 
        uint32_t o_visible_size = 0x1D4C;
        uint32_t o_visible_pointer = 0x1F8;
        uint32_t o_visible_cached_base = 0x78;
        uint32_t o_visible_cmp_index = 0x1EE;
        uint32_t o_visible_cmp_function = 0xD4B0660;
        uint32_t o_visible_cmp_value = 0x29;
 
        uint32_t o_bone_base = 0x17AB28;
        uint32_t o_bone_size = 0x188;
 
        uint32_t o_game_mode = 0x11CF1570;
 
        uint32_t o_no_recoil = 0x96BC;
        uint32_t o_weapon_definition = 0x15014490;
 
        uint32_t o_player_dead_1 = 0x1300C;
        uint32_t o_player_dead_2 = 0x1300C;
        uint32_t o_player_pos = 0x2A0;
        uint32_t o_player_size = 0x13DE0;
        uint32_t o_player_team = 0xA2;
        uint32_t o_player_valid = 0x12758;
        uint32_t o_player_weapon_index = 0x1267E;
 
        uint32_t o_entity_size = 0x3E8;
        uint32_t o_entity_type = 0x28C;
        uint32_t o_entity_index = 0x284;
        uint32_t o_entity_valid = 0x25C;
        uint32_t o_entity_pos = o_entity_type + 0x18;
 
        uint32_t o_name_array = 0x1512BD58;
        uint32_t o_name_array_padding = 0x2C80;
        uint32_t o_name_array_size = 0xC0;
};
 
 
uintptr_t decrypt_client_info()
{
        uint64_t mb = mb;
        uint64_t rax = mb, rbx = mb, rcx = mb, rdx = mb, rdi = mb, rsi = mb, r8 = mb, r9 = mb, r10 = mb, r11 = mb, r12 = mb, r13 = mb, r14 = mb, r15 = mb;
 
        rbx = *(uintptr_t*)(mb + 0x14F4F248);
        if(!rbx)
                return rbx;
 
        rdx = st::peb;          //mov rdx, gs:[rax]
//failed to trace. Register value: r8 = 000000000000036C. base: 00007FF7241E0000 It's possibly wrong
        rcx = rbx + r8 * 1;             //lea rcx, [rbx+r8*1]
        rax = 0;                //and rax, 0xFFFFFFFFC0000000
        rax = _rotl64(rax, 0x10);               //rol rax, 0x10
        rax ^= *(uintptr_t*)(mb + 0xB5640E5);               //xor rax, [0x0000000002E23EC4]
        rax = _byteswap_uint64(rax);            //bswap rax
        rcx *= *(uintptr_t*)(rax + 0x5);                 //imul rcx, [rax+0x05]
        rax = mb + 0x37489F9E;             //lea rax, [0x000000002ED49D6E]
        rdx ^= rax;             //xor rdx, rax
        rcx += rdx;             //add rcx, rdx
        rax = rcx;              //mov rax, rcx
        rax >>= 0x13;           //shr rax, 0x13
        rcx ^= rax;             //xor rcx, rax
        rax = 0xF7B4615B6CAAA4C7;               //mov rax, 0xF7B4615B6CAAA4C7
        rbx = rcx;              //mov rbx, rcx
        rbx >>= 0x26;           //shr rbx, 0x26
        rbx ^= rcx;             //xor rbx, rcx
        rbx ^= rax;             //xor rbx, rax
        rax = 0x4FBE922616062817;               //mov rax, 0x4FBE922616062817
        rbx *= rax;             //imul rbx, rax
        return rbx;
};
 
uintptr_t decrypt_client_base(uintptr_t client_info)
{
        uint64_t mb = mb;
        uint64_t rax = mb, rbx = mb, rcx = mb, rdx = mb, rdi = mb, rsi = mb, r8 = mb, r9 = mb, r10 = mb, r11 = mb, r12 = mb, r13 = mb, r14 = mb, r15 = mb;
 
        rax = *(uintptr_t*)(client_info + 0x199718);
        if(!rax)
                return rax;
 
        r11= ~st::peb;          //mov r11, gs:[rcx]
        rcx = r11;              //mov rcx, r11
        //failed to translate: mov [rsp+0x3D0], r13
        rcx <<= 0x23;           //shl rcx, 0x23
        rcx = _byteswap_uint64(rcx);            //bswap rcx
        rcx &= 0xF;
 
        switch(rcx)
        {
        case 0:
        {
                r10 = *(uintptr_t*)(mb + 0xB56412C);                //mov r10, [0x0000000007F0D3D2]
                rdx = mb + 0x736B1CC9;             //lea rdx, [0x000000007005AEEE]
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x4;            //shr rcx, 0x04
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x8;            //shr rcx, 0x08
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x10;           //shr rcx, 0x10
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x20;           //shr rcx, 0x20
                rax ^= rcx;             //xor rax, rcx
                rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
                rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
                rcx ^= r10;             //xor rcx, r10
                rcx = ~rcx;             //not rcx
                rcx = *(uintptr_t*)(rcx + 0x9);          //mov rcx, [rcx+0x09]
                uintptr_t RSP_0x40;
                RSP_0x40 = 0xEDD02482923403CB;          //mov rcx, 0xEDD02482923403CB : RSP+0x40
                rcx *= RSP_0x40;                //imul rcx, [rsp+0x40]
                rax *= rcx;             //imul rax, rcx
                rcx = r11;              //mov rcx, r11
                rcx -= mb;                 //sub rcx, [rbp-0x80] -- didn't find trace -> use base
                rcx += 0xFFFFFFFFC99E5582;              //add rcx, 0xFFFFFFFFC99E5582
                rax += rcx;             //add rax, rcx
                rcx = mb;          //lea rcx, [0xFFFFFFFFFC9A90DC]
                rax ^= rcx;             //xor rax, rcx
                rcx = 0x26A471A9EFBC14B9;               //mov rcx, 0x26A471A9EFBC14B9
                rax *= rcx;             //imul rax, rcx
                rcx = r11;              //mov rcx, r11
                rcx = ~rcx;             //not rcx
                rcx ^= rdx;             //xor rcx, rdx
                rax -= rcx;             //sub rax, rcx
                rcx = 0x4E231C434132699A;               //mov rcx, 0x4E231C434132699A
                rax += rcx;             //add rax, rcx
                return rax;
        }
        case 1:
        {
                r9 = *(uintptr_t*)(mb + 0xB56412C);                 //mov r9, [0x0000000007F0CECC]
                r13 = mb + 0x2239B1C1;             //lea r13, [0x000000001ED43F42]
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x15;           //shr rcx, 0x15
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x2A;           //shr rcx, 0x2A
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0xA;            //shr rcx, 0x0A
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x14;           //shr rcx, 0x14
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x28;           //shr rcx, 0x28
                rax ^= rcx;             //xor rax, rcx
                rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
                rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
                rcx ^= r9;              //xor rcx, r9
                rcx = ~rcx;             //not rcx
                rax *= *(uintptr_t*)(rcx + 0x9);                 //imul rax, [rcx+0x09]
                rcx = 0x3E63A253C6775D5;                //mov rcx, 0x3E63A253C6775D5
                rax ^= rcx;             //xor rax, rcx
                rcx = 0xC1F5691FD75F11C7;               //mov rcx, 0xC1F5691FD75F11C7
                rax *= rcx;             //imul rax, rcx
                rax += 0xFFFFFFFFDA4F9118;              //add rax, 0xFFFFFFFFDA4F9118
                rax += r11;             //add rax, r11
                rcx = r13;              //mov rcx, r13
                rcx = ~rcx;             //not rcx
                rcx ^= r11;             //xor rcx, r11
                rax += rcx;             //add rax, rcx
                return rax;
        }
        case 2:
        {
                r10 = *(uintptr_t*)(mb + 0xB56412C);                //mov r10, [0x0000000007F0C9ED]
                rcx = 0x43AE441D8481DD04;               //mov rcx, 0x43AE441D8481DD04
                rax -= rcx;             //sub rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x26;           //shr rcx, 0x26
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x9;            //shr rcx, 0x09
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x12;           //shr rcx, 0x12
                rax ^= rcx;             //xor rax, rcx
                rdx = rax;              //mov rdx, rax
                rdx >>= 0x24;           //shr rdx, 0x24
                rdx ^= rax;             //xor rdx, rax
                rcx = r11;              //mov rcx, r11
                rax = mb + 0x424950C8;             //lea rax, [0x000000003EE3D739]
                rcx = ~rcx;             //not rcx
                rax *= rcx;             //imul rax, rcx
                rax += rdx;             //add rax, rdx
                rcx = 0x1EB0B3B479EF017;                //mov rcx, 0x1EB0B3B479EF017
                rax *= rcx;             //imul rax, rcx
                rcx = 0xF4FDCF8C05766D07;               //mov rcx, 0xF4FDCF8C05766D07
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x17;           //shr rcx, 0x17
                rax ^= rcx;             //xor rax, rcx
                rdx = 0;                //and rdx, 0xFFFFFFFFC0000000
                rdx = _rotl64(rdx, 0x10);               //rol rdx, 0x10
                rcx = rax;              //mov rcx, rax
                rdx ^= r10;             //xor rdx, r10
                rcx >>= 0x2E;           //shr rcx, 0x2E
                rdx = ~rdx;             //not rdx
                rax ^= rcx;             //xor rax, rcx
                rax *= *(uintptr_t*)(rdx + 0x9);                 //imul rax, [rdx+0x09]
                return rax;
        }
        case 3:
        {
                r10 = *(uintptr_t*)(mb + 0xB56412C);                //mov r10, [0x0000000007F0C495]
                r13 = mb + 0x1488BAD0;             //lea r13, [0x0000000011233E26]
                rdx = r11;              //mov rdx, r11
                rdx = ~rdx;             //not rdx
                rcx = mb + 0x8952;                 //lea rcx, [0xFFFFFFFFFC9B092A]
                rcx = ~rcx;             //not rcx
                rdx *= rcx;             //imul rdx, rcx
                rcx = 0x920D8D54066C3BC8;               //mov rcx, 0x920D8D54066C3BC8
                rax ^= rdx;             //xor rax, rdx
                rax ^= rcx;             //xor rax, rcx
                rcx = 0x71B6A01168176A5F;               //mov rcx, 0x71B6A01168176A5F
                rax *= rcx;             //imul rax, rcx
                rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
                rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
                rcx ^= r10;             //xor rcx, r10
                rcx = ~rcx;             //not rcx
                rax *= *(uintptr_t*)(rcx + 0x9);                 //imul rax, [rcx+0x09]
                rcx = rax;              //mov rcx, rax
                rcx >>= 0xB;            //shr rcx, 0x0B
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x16;           //shr rcx, 0x16
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x2C;           //shr rcx, 0x2C
                rax ^= rcx;             //xor rax, rcx
                rcx = 0x28C4EBE07CC779E5;               //mov rcx, 0x28C4EBE07CC779E5
                rax ^= rcx;             //xor rax, rcx
                rcx = r11;              //mov rcx, r11
                rcx *= r13;             //imul rcx, r13
                rax -= rcx;             //sub rax, rcx
                rax += r11;             //add rax, r11
                return rax;
        }
        case 4:
        {
                r10 = *(uintptr_t*)(mb + 0xB56412C);                //mov r10, [0x0000000007F0BFAB]
                r13 = mb + 0x71CF;                 //lea r13, [0xFFFFFFFFFC9AF03B]
                rcx = 0x7BD4F3C29580BB87;               //mov rcx, 0x7BD4F3C29580BB87
                rax *= rcx;             //imul rax, rcx
                rcx = 0x646EC108C275FCD7;               //mov rcx, 0x646EC108C275FCD7
                rax -= r11;             //sub rax, r11
                rax -= rcx;             //sub rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x1B;           //shr rcx, 0x1B
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x36;           //shr rcx, 0x36
                rax ^= rcx;             //xor rax, rcx
                rcx = 0x142843BCE5FD72BB;               //mov rcx, 0x142843BCE5FD72BB
                rdx = 0;                //and rdx, 0xFFFFFFFFC0000000
                rdx = _rotl64(rdx, 0x10);               //rol rdx, 0x10
                rax *= rcx;             //imul rax, rcx
                rdx ^= r10;             //xor rdx, r10
                rdx = ~rdx;             //not rdx
                rax += r11;             //add rax, r11
                rax *= *(uintptr_t*)(rdx + 0x9);                 //imul rax, [rdx+0x09]
                rcx = r11;              //mov rcx, r11
                rcx = ~rcx;             //not rcx
                rcx ^= r13;             //xor rcx, r13
                rax -= rcx;             //sub rax, rcx
                return rax;
        }
        case 5:
        {
                r10 = *(uintptr_t*)(mb + 0xB56412C);                //mov r10, [0x0000000007F0BBD5]
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x9;            //shr rcx, 0x09
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x12;           //shr rcx, 0x12
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x24;           //shr rcx, 0x24
                rax ^= rcx;             //xor rax, rcx
                rcx = mb;          //lea rcx, [0xFFFFFFFFFC9A74E0]
                rcx += 0x111FC085;              //add rcx, 0x111FC085
                rcx += r11;             //add rcx, r11
                rax += rcx;             //add rax, rcx
                rcx = 0xF8D94370868AB99;                //mov rcx, 0xF8D94370868AB99
                rax *= rcx;             //imul rax, rcx
                rcx = 0xB026072E428E1D57;               //mov rcx, 0xB026072E428E1D57
                rax *= rcx;             //imul rax, rcx
                rcx = mb;          //lea rcx, [0xFFFFFFFFFC9A76B0]
                rcx += 0x19F5;          //add rcx, 0x19F5
                rcx += r11;             //add rcx, r11
                rax += rcx;             //add rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x23;           //shr rcx, 0x23
                rax ^= rcx;             //xor rax, rcx
                rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
                rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
                rcx ^= r10;             //xor rcx, r10
                rcx = ~rcx;             //not rcx
                rcx = *(uintptr_t*)(rcx + 0x9);          //mov rcx, [rcx+0x09]
                uintptr_t RSP_0x40;
                RSP_0x40 = 0x5F23D3FEF0707261;          //mov rcx, 0x5F23D3FEF0707261 : RSP+0x40
                rcx *= RSP_0x40;                //imul rcx, [rsp+0x40]
                rax *= rcx;             //imul rax, rcx
                return rax;
        }
        case 6:
        {
                r9 = *(uintptr_t*)(mb + 0xB56412C);                 //mov r9, [0x0000000007F0B5E6]
                rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
                rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
                rcx ^= r9;              //xor rcx, r9
                rcx = ~rcx;             //not rcx
                rax *= *(uintptr_t*)(rcx + 0x9);                 //imul rax, [rcx+0x09]
                rax -= r11;             //sub rax, r11
                rcx = mb + 0x43B5;                 //lea rcx, [0xFFFFFFFFFC9AB6DC]
                rcx -= r11;             //sub rcx, r11
                rax += rcx;             //add rax, rcx
                rcx = 0x35284D873B9851A9;               //mov rcx, 0x35284D873B9851A9
                rax ^= rcx;             //xor rax, rcx
                rcx = 0xF62B33C5DDB521B5;               //mov rcx, 0xF62B33C5DDB521B5
                rax *= rcx;             //imul rax, rcx
                rcx = 0xE5B0BD16F00B9D46;               //mov rcx, 0xE5B0BD16F00B9D46
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0xA;            //shr rcx, 0x0A
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x14;           //shr rcx, 0x14
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x28;           //shr rcx, 0x28
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x19;           //shr rcx, 0x19
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x32;           //shr rcx, 0x32
                rax ^= rcx;             //xor rax, rcx
                return rax;
        }
        case 7:
        {
                r10 = *(uintptr_t*)(mb + 0xB56412C);                //mov r10, [0x0000000007F0B151]
                rdx = mb + 0x8CB4;                 //lea rdx, [0xFFFFFFFFFC9AFC6F]
                rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
                rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
                rcx ^= r10;             //xor rcx, r10
                rcx = ~rcx;             //not rcx
                rax *= *(uintptr_t*)(rcx + 0x9);                 //imul rax, [rcx+0x09]
                rcx = mb;          //lea rcx, [0xFFFFFFFFFC9A6C24]
                rax -= rcx;             //sub rax, rcx
                rcx = 0x9A8F75E5FE8A18B5;               //mov rcx, 0x9A8F75E5FE8A18B5
                rax *= rcx;             //imul rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x26;           //shr rcx, 0x26
                rax ^= rcx;             //xor rax, rcx
                rax += r11;             //add rax, r11
                rcx = 0xDC35AEB9AD64C433;               //mov rcx, 0xDC35AEB9AD64C433
                rax *= rcx;             //imul rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x2;            //shr rcx, 0x02
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x4;            //shr rcx, 0x04
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x8;            //shr rcx, 0x08
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x10;           //shr rcx, 0x10
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x20;           //shr rcx, 0x20
                rax ^= rcx;             //xor rax, rcx
                rcx = r11 + 0x1;                //lea rcx, [r11+0x01]
                rcx *= rdx;             //imul rcx, rdx
                rax += rcx;             //add rax, rcx
                return rax;
        }
        case 8:
        {
                r9 = *(uintptr_t*)(mb + 0xB56412C);                 //mov r9, [0x0000000007F0ACA7]
                rcx = 0x4F7CA4829AB6D5E8;               //mov rcx, 0x4F7CA4829AB6D5E8
                rax ^= rcx;             //xor rax, rcx
                rax += r11;             //add rax, r11
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x24;           //shr rcx, 0x24
                rax ^= rcx;             //xor rax, rcx
                rcx = 0x5178F05F16D45A5B;               //mov rcx, 0x5178F05F16D45A5B
                rax *= rcx;             //imul rax, rcx
                rcx = 0x2ED8CECF4C40E0F3;               //mov rcx, 0x2ED8CECF4C40E0F3
                rax ^= r11;             //xor rax, r11
                rax ^= rcx;             //xor rax, rcx
                rax ^= r11;             //xor rax, r11
                rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
                rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
                rcx ^= r9;              //xor rcx, r9
                rcx = ~rcx;             //not rcx
                rax *= *(uintptr_t*)(rcx + 0x9);                 //imul rax, [rcx+0x09]
                return rax;
        }
        case 9:
        {
                r10 = *(uintptr_t*)(mb + 0xB56412C);                //mov r10, [0x0000000007F0A89B]
                rdx = mb + 0xDD4D;                 //lea rdx, [0xFFFFFFFFFC9B4452]
                rcx = r11;              //mov rcx, r11
                rcx ^= rdx;             //xor rcx, rdx
                rax += rcx;             //add rax, rcx
                rcx = 0x8BE287ECF689749;                //mov rcx, 0x8BE287ECF689749
                rax *= rcx;             //imul rax, rcx
                rax ^= r11;             //xor rax, r11
                rcx = 0x9933D7378FE6958F;               //mov rcx, 0x9933D7378FE6958F
                rax *= rcx;             //imul rax, rcx
                rdx = 0;                //and rdx, 0xFFFFFFFFC0000000
                rdx = _rotl64(rdx, 0x10);               //rol rdx, 0x10
                rdx ^= r10;             //xor rdx, r10
                rcx = mb + 0x66BC28B6;             //lea rcx, [0x0000000063568CA3]
                rcx = ~rcx;             //not rcx
                rdx = ~rdx;             //not rdx
                rcx ^= r11;             //xor rcx, r11
                rax += rcx;             //add rax, rcx
                rax *= *(uintptr_t*)(rdx + 0x9);                 //imul rax, [rdx+0x09]
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x20;           //shr rcx, 0x20
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x18;           //shr rcx, 0x18
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x30;           //shr rcx, 0x30
                rax ^= rcx;             //xor rax, rcx
                return rax;
        }
        case 10:
        {
                r10 = *(uintptr_t*)(mb + 0xB56412C);                //mov r10, [0x0000000007F0A464]
                rcx = rax;              //mov rcx, rax
                rcx >>= 0xD;            //shr rcx, 0x0D
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x1A;           //shr rcx, 0x1A
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x34;           //shr rcx, 0x34
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x13;           //shr rcx, 0x13
                rax ^= rcx;             //xor rax, rcx
                rdx = rax;              //mov rdx, rax
                rdx >>= 0x26;           //shr rdx, 0x26
                rdx ^= rax;             //xor rdx, rax
                rax = mb + 0x1C730DA6;             //lea rax, [0x00000000190D6FB8]
                rcx = r11;              //mov rcx, r11
                rcx *= rax;             //imul rcx, rax
                rax = rdx;              //mov rax, rdx
                rax -= rcx;             //sub rax, rcx
                rcx = 0x4D5CFB5CBF920449;               //mov rcx, 0x4D5CFB5CBF920449
                rax ^= rcx;             //xor rax, rcx
                rcx = 0xDF1CB3CC3968ECE9;               //mov rcx, 0xDF1CB3CC3968ECE9
                rax *= rcx;             //imul rax, rcx
                rax ^= r11;             //xor rax, r11
                rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
                rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
                rcx ^= r10;             //xor rcx, r10
                rcx = ~rcx;             //not rcx
                rax *= *(uintptr_t*)(rcx + 0x9);                 //imul rax, [rcx+0x09]
                return rax;
        }
        case 11:
        {
                r10 = *(uintptr_t*)(mb + 0xB56412C);                //mov r10, [0x0000000007F09EB7]
                rcx = mb + 0xE27A;                 //lea rcx, [0xFFFFFFFFFC9B3D69]
                rcx -= r11;             //sub rcx, r11
                rdx = 0;                //and rdx, 0xFFFFFFFFC0000000
                rax += rcx;             //add rax, rcx
                rdx = _rotl64(rdx, 0x10);               //rol rdx, 0x10
                rdx ^= r10;             //xor rdx, r10
                rdx = ~rdx;             //not rdx
                rax *= *(uintptr_t*)(rdx + 0x9);                 //imul rax, [rdx+0x09]
                rcx = r11;              //mov rcx, r11
                rcx -= mb;                 //sub rcx, [rbp-0x80] -- didn't find trace -> use base
                rcx += 0xFFFFFFFFBE05F030;              //add rcx, 0xFFFFFFFFBE05F030
                rax += rcx;             //add rax, rcx
                rcx = 0x8407AE81269A5D57;               //mov rcx, 0x8407AE81269A5D57
                rax *= rcx;             //imul rax, rcx
                rax -= r11;             //sub rax, r11
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x25;           //shr rcx, 0x25
                rax ^= rcx;             //xor rax, rcx
                rcx = 0x4D58E84452B3B2CD;               //mov rcx, 0x4D58E84452B3B2CD
                rax += rcx;             //add rax, rcx
                return rax;
        }
        case 12:
        {
                r10 = *(uintptr_t*)(mb + 0xB56412C);                //mov r10, [0x0000000007F09940]
                rcx = rax;              //mov rcx, rax
                rcx >>= 0xE;            //shr rcx, 0x0E
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x1C;           //shr rcx, 0x1C
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x38;           //shr rcx, 0x38
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x21;           //shr rcx, 0x21
                rax ^= rcx;             //xor rax, rcx
                rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
                rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
                rcx ^= r10;             //xor rcx, r10
                rcx = ~rcx;             //not rcx
                rax *= *(uintptr_t*)(rcx + 0x9);                 //imul rax, [rcx+0x09]
                rcx = 0x12FD53752A15F441;               //mov rcx, 0x12FD53752A15F441
                rax *= rcx;             //imul rax, rcx
                rcx = mb + 0x2A01C819;             //lea rcx, [0x00000000269C1BED]
                rcx *= r11;             //imul rcx, r11
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x2;            //shr rcx, 0x02
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x4;            //shr rcx, 0x04
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x8;            //shr rcx, 0x08
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x10;           //shr rcx, 0x10
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x20;           //shr rcx, 0x20
                rax ^= rcx;             //xor rax, rcx
                rcx = 0x438F040A11D1F693;               //mov rcx, 0x438F040A11D1F693
                rax *= rcx;             //imul rax, rcx
                rcx = 0x76A8417B55AEC887;               //mov rcx, 0x76A8417B55AEC887
                rax += rcx;             //add rax, rcx
                return rax;
        }
        case 13:
        {
                r9 = *(uintptr_t*)(mb + 0xB56412C);                 //mov r9, [0x0000000007F093D0]
                r12 = mb + 0xB0AA;                 //lea r12, [0xFFFFFFFFFC9B033B]
                rcx = r12;              //mov rcx, r12
                rcx = ~rcx;             //not rcx
                rcx ^= r11;             //xor rcx, r11
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x18;           //shr rcx, 0x18
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x30;           //shr rcx, 0x30
                rax ^= rcx;             //xor rax, rcx
                rcx = 0xC32A740461B9FDC7;               //mov rcx, 0xC32A740461B9FDC7
                rax *= rcx;             //imul rax, rcx
                rcx = 0x9439B00A1FEFA912;               //mov rcx, 0x9439B00A1FEFA912
                rax ^= rcx;             //xor rax, rcx
                rcx = 0x2B3AD1E7D117AD86;               //mov rcx, 0x2B3AD1E7D117AD86
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x27;           //shr rcx, 0x27
                rax ^= rcx;             //xor rax, rcx
                rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
                rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
                rcx ^= r9;              //xor rcx, r9
                rcx = ~rcx;             //not rcx
                rax *= *(uintptr_t*)(rcx + 0x9);                 //imul rax, [rcx+0x09]
                rcx = mb;          //lea rcx, [0xFFFFFFFFFC9A4DB5]
                rax ^= rcx;             //xor rax, rcx
                return rax;
        }
        case 14:
        {
                r10 = *(uintptr_t*)(mb + 0xB56412C);                //mov r10, [0x0000000007F08EC5]
                r13 = mb + 0x6A35;                 //lea r13, [0xFFFFFFFFFC9AB7B6]
                rax -= r11;             //sub rax, r11
                rcx = 0xEEEEF35687DD1DF7;               //mov rcx, 0xEEEEF35687DD1DF7
                rax *= rcx;             //imul rax, rcx
                rcx = mb + 0x913D;                 //lea rcx, [0xFFFFFFFFFC9ADCFB]
                rcx *= r11;             //imul rcx, r11
                rax ^= rcx;             //xor rax, rcx
                rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
                rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
                rcx ^= r10;             //xor rcx, r10
                rcx = ~rcx;             //not rcx
                rcx = *(uintptr_t*)(rcx + 0x9);          //mov rcx, [rcx+0x09]
                uintptr_t RSP_0x28;
                RSP_0x28 = 0x571AF583F00DB5E9;          //mov rcx, 0x571AF583F00DB5E9 : RSP+0x28
                rcx *= RSP_0x28;                //imul rcx, [rsp+0x28]
                rax *= rcx;             //imul rax, rcx
                rcx = rax;              //mov rcx, rax
                rdx = r13;              //mov rdx, r13
                rcx >>= 0x21;           //shr rcx, 0x21
                rdx -= r11;             //sub rdx, r11
                rdx ^= rcx;             //xor rdx, rcx
                rax ^= rdx;             //xor rax, rdx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x24;           //shr rcx, 0x24
                rax ^= rcx;             //xor rax, rcx
                return rax;
        }
        case 15:
        {
                r10 = *(uintptr_t*)(mb + 0xB56412C);                //mov r10, [0x0000000007F0895B]
                rcx = 0x586536E499271C5;                //mov rcx, 0x586536E499271C5
                rax *= rcx;             //imul rax, rcx
                rcx = mb + 0xB0F6;                 //lea rcx, [0xFFFFFFFFFC9AF547]
                rdx = r11;              //mov rdx, r11
                rdx -= rcx;             //sub rdx, rcx
                rcx = mb + 0x2941AF47;             //lea rcx, [0x0000000025DBF38B]
                rcx *= r11;             //imul rcx, r11
                rax ^= rdx;             //xor rax, rdx
                rax -= rcx;             //sub rax, rcx
                uintptr_t RSP_0x38;
                RSP_0x38 = 0xF66CBDFA6519136F;          //mov rcx, 0xF66CBDFA6519136F : RSP+0x38
                rax ^= RSP_0x38;                //xor rax, [rsp+0x38]
                rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
                rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
                rcx ^= r10;             //xor rcx, r10
                rcx = ~rcx;             //not rcx
                rax *= *(uintptr_t*)(rcx + 0x9);                 //imul rax, [rcx+0x09]
                rax ^= r11;             //xor rax, r11
                rcx = mb;          //lea rcx, [0xFFFFFFFFFC9A45CA]
                rax -= rcx;             //sub rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x1E;           //shr rcx, 0x1E
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x3C;           //shr rcx, 0x3C
                rax ^= rcx;             //xor rax, rcx
                return rax;
        }
        }
};
 
uintptr_t get_bone_index(uint32_t bone_index)
{
        uint64_t mb = mb;
        uint64_t rax = mb, rbx = mb, rcx = mb, rdx = mb, rdi = mb, rsi = mb, r8 = mb, r9 = mb, r10 = mb, r11 = mb, r12 = mb, r13 = mb, r14 = mb, r15 = mb;
 
        rdi = bone_index;
        rcx = rdi * 0x13C8;
        rax = 0xCC70CD3D3E0A7B49;               //mov rax, 0xCC70CD3D3E0A7B49
        rax = _umul128(rax, rcx, (uintptr_t*)&rdx);             //mul rcx
        r11 = mb;          //lea r11, [0xFFFFFFFFFD76A845]
        r10 = 0x45F86A52798F52B7;               //mov r10, 0x45F86A52798F52B7
        rdx >>= 0xC;            //shr rdx, 0x0C
        rax = rdx * 0x1409;             //imul rax, rdx, 0x1409
        rcx -= rax;             //sub rcx, rax
        rax = 0xDC9D0ECFCB6E9379;               //mov rax, 0xDC9D0ECFCB6E9379
        r8 = rcx * 0x1409;              //imul r8, rcx, 0x1409
        rax = _umul128(rax, r8, (uintptr_t*)&rdx);              //mul r8
        rdx >>= 0xD;            //shr rdx, 0x0D
        rax = rdx * 0x2522;             //imul rax, rdx, 0x2522
        r8 -= rax;              //sub r8, rax
        rax = 0x49539E3B2D066EA3;               //mov rax, 0x49539E3B2D066EA3
        rax = _umul128(rax, r8, (uintptr_t*)&rdx);              //mul r8
        rax = r8;               //mov rax, r8
        rax -= rdx;             //sub rax, rdx
        rax >>= 0x1;            //shr rax, 0x01
        rax += rdx;             //add rax, rdx
        rax >>= 0x9;            //shr rax, 0x09
        rcx = rax * 0x31C;              //imul rcx, rax, 0x31C
        rax = 0xD79435E50D79435F;               //mov rax, 0xD79435E50D79435F
        rax = _umul128(rax, r8, (uintptr_t*)&rdx);              //mul r8
        rdx >>= 0x4;            //shr rdx, 0x04
        rcx += rdx;             //add rcx, rdx
        rax = rcx * 0x26;               //imul rax, rcx, 0x26
        rcx = r8 + r8 * 4;              //lea rcx, [r8+r8*4]
        rcx <<= 0x3;            //shl rcx, 0x03
        rcx -= rax;             //sub rcx, rax
        rax = p_mem.read<uint16_t>(rcx + r11 * 1 + 0xB5FE3D0);          //movzx eax, word ptr [rcx+r11*1+0xB5FE3D0]
        r8 = rax * 0x13C8;              //imul r8, rax, 0x13C8
        rax = r10;              //mov rax, r10
        rax = _umul128(rax, r8, (uintptr_t*)&rdx);              //mul r8
        rax = r10;              //mov rax, r10
        rdx >>= 0xB;            //shr rdx, 0x0B
        rcx = rdx * 0x1D45;             //imul rcx, rdx, 0x1D45
        r8 -= rcx;              //sub r8, rcx
        r9 = r8 * 0x39A6;               //imul r9, r8, 0x39A6
        rax = _umul128(rax, r9, (uintptr_t*)&rdx);              //mul r9
        rdx >>= 0xB;            //shr rdx, 0x0B
        rax = rdx * 0x1D45;             //imul rax, rdx, 0x1D45
        r9 -= rax;              //sub r9, rax
        rax = 0x88ECF206D1CD0DD7;               //mov rax, 0x88ECF206D1CD0DD7
        rax = _umul128(rax, r9, (uintptr_t*)&rdx);              //mul r9
        rax = 0xAAAAAAAAAAAAAAAB;               //mov rax, 0xAAAAAAAAAAAAAAAB
        rdx >>= 0xB;            //shr rdx, 0x0B
        rcx = rdx * 0xEF5;              //imul rcx, rdx, 0xEF5
        rax = _umul128(rax, r9, (uintptr_t*)&rdx);              //mul r9
        rdx >>= 0x1;            //shr rdx, 0x01
        rcx += rdx;             //add rcx, rdx
        rax = rcx + rcx * 2;            //lea rax, [rcx+rcx*2]
        rax += rax;             //add rax, rax
        rcx = r9 * 8 + 0x0;             //lea rcx, [r9*8]
        rcx -= rax;             //sub rcx, rax
        r15 = p_mem.read<uint16_t>(rcx + r11 * 1 + 0xB605A00);          //movsx r15d, word ptr [rcx+r11*1+0xB605A00]
        return r15;
};
 
uintptr_t decrypt_bone_base()
{
        uint64_t mb = mb;
        uint64_t rax = mb, rbx = mb, rcx = mb, rdx = mb, rdi = mb, rsi = mb, r8 = mb, r9 = mb, r10 = mb, r11 = mb, r12 = mb, r13 = mb, r14 = mb, r15 = mb;
 
        rax = *(uintptr_t*)(mb + 0xFA26F58);
        if(!rax)
                return rax;
 
        rbx = st::peb;          //mov rbx, gs:[rcx]
        //failed to translate: jz 0x0000000000004A97
        rcx = rbx;              //mov rcx, rbx
        //failed to translate: mov [rsp+0xD8], r13
        rcx = _rotr64(rcx, 0x1A);               //ror rcx, 0x1A
        rcx &= 0xF;
 
        switch(rcx)
        {
        case 0:
        {
                r9 = *(uintptr_t*)(mb + 0xB56421D);                 //mov r9, [0x00000000060F98B8]
                r11 = mb + 0x9280;                 //lea r11, [0xFFFFFFFFFAB9E908]
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x26;           //shr rcx, 0x26
                rax ^= rcx;             //xor rax, rcx
                rcx = 0x1409F0CD847A37CE;               //mov rcx, 0x1409F0CD847A37CE
                rax ^= rcx;             //xor rax, rcx
                rcx = rbx;              //mov rcx, rbx
                rcx = ~rcx;             //not rcx
                rcx ^= r11;             //xor rcx, r11
                rax += rcx;             //add rax, rcx
                rcx = 0x3C34D747DB7928EE;               //mov rcx, 0x3C34D747DB7928EE
                rax -= rcx;             //sub rax, rcx
                rcx = mb + 0xDB7F;                 //lea rcx, [0xFFFFFFFFFABA3029]
                rcx = ~rcx;             //not rcx
                rcx -= rbx;             //sub rcx, rbx
                rax ^= rcx;             //xor rax, rcx
                rcx = 0xC029A5A1D42718DD;               //mov rcx, 0xC029A5A1D42718DD
                rax *= rcx;             //imul rax, rcx
                rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
                rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
                rcx ^= r9;              //xor rcx, r9
                rcx = ~rcx;             //not rcx
                rax *= *(uintptr_t*)(rcx + 0x15);                //imul rax, [rcx+0x15]
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x7;            //shr rcx, 0x07
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0xE;            //shr rcx, 0x0E
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x1C;           //shr rcx, 0x1C
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x38;           //shr rcx, 0x38
                rax ^= rcx;             //xor rax, rcx
                return rax;
        }
        case 1:
        {
                r9 = *(uintptr_t*)(mb + 0xB56421D);                 //mov r9, [0x00000000060F9341]
                r11 = mb;          //lea r11, [0xFFFFFFFFFAB95111]
                r13 = mb + 0x54CA1D31;             //lea r13, [0x000000004F836E37]
                rax += rbx;             //add rax, rbx
                rax += r11;             //add rax, r11
                rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
                rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
                rcx ^= r9;              //xor rcx, r9
                rcx = ~rcx;             //not rcx
                rax *= *(uintptr_t*)(rcx + 0x15);                //imul rax, [rcx+0x15]
                rcx = 0x48462EAD4F11FD6D;               //mov rcx, 0x48462EAD4F11FD6D
                rax *= rcx;             //imul rax, rcx
                rcx = rbx;              //mov rcx, rbx
                rcx ^= r13;             //xor rcx, r13
                rax -= rcx;             //sub rax, rcx
                rcx = 0x83B3774C1397A303;               //mov rcx, 0x83B3774C1397A303
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x26;           //shr rcx, 0x26
                rax ^= rcx;             //xor rax, rcx
                rcx = 0x829707C28057B2BC;               //mov rcx, 0x829707C28057B2BC
                rax ^= rcx;             //xor rax, rcx
                return rax;
        }
        case 2:
        {
                r9 = *(uintptr_t*)(mb + 0xB56421D);                 //mov r9, [0x00000000060F8E87]
                r11 = mb;          //lea r11, [0xFFFFFFFFFAB94C57]
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x20;           //shr rcx, 0x20
                rax ^= rcx;             //xor rax, rcx
                rax ^= r11;             //xor rax, r11
                rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
                rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
                rcx ^= r9;              //xor rcx, r9
                rcx = ~rcx;             //not rcx
                rax *= *(uintptr_t*)(rcx + 0x15);                //imul rax, [rcx+0x15]
                rcx = rbx;              //mov rcx, rbx
                uintptr_t RSP_0xFFFFFFFFFFFFFFCF;
                RSP_0xFFFFFFFFFFFFFFCF = mb + 0x3A246E06;          //lea rcx, [0x0000000034DDBA48] : RBP+0xFFFFFFFFFFFFFFCF
                rcx ^= RSP_0xFFFFFFFFFFFFFFCF;          //xor rcx, [rbp-0x31]
                rax += rcx;             //add rax, rcx
                rcx = 0xC391B266D5217A5F;               //mov rcx, 0xC391B266D5217A5F
                rax ^= rcx;             //xor rax, rcx
                rcx = 0x5B7F3E818AF67A35;               //mov rcx, 0x5B7F3E818AF67A35
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x1A;           //shr rcx, 0x1A
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x34;           //shr rcx, 0x34
                rax ^= rcx;             //xor rax, rcx
                rcx = 0x19C8F1552DE67BBF;               //mov rcx, 0x19C8F1552DE67BBF
                rax *= rcx;             //imul rax, rcx
                return rax;
        }
        case 3:
        {
                r9 = *(uintptr_t*)(mb + 0xB56421D);                 //mov r9, [0x00000000060F89C3]
                rcx = mb + 0xBD6;          //lea rcx, [0xFFFFFFFFFAB9517E]
                rcx -= rbx;             //sub rcx, rbx
                rcx ^= rbx;             //xor rcx, rbx
                rax ^= rcx;             //xor rax, rcx
                rcx = 0xAA6F288FD0E3CBF;                //mov rcx, 0xAA6F288FD0E3CBF
                rax *= rcx;             //imul rax, rcx
                r13 = 0x702F07A4D309E97C;               //mov r13, 0x702F07A4D309E97C
                rax += r13;             //add rax, r13
                rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
                rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
                rcx ^= r9;              //xor rcx, r9
                rcx = ~rcx;             //not rcx
                rax *= *(uintptr_t*)(rcx + 0x15);                //imul rax, [rcx+0x15]
                rax ^= rbx;             //xor rax, rbx
                rcx = 0x65D0349BA5FED43B;               //mov rcx, 0x65D0349BA5FED43B
                rax *= rcx;             //imul rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x12;           //shr rcx, 0x12
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x24;           //shr rcx, 0x24
                rax ^= rcx;             //xor rax, rcx
                return rax;
        }
        case 4:
        {
                r10 = *(uintptr_t*)(mb + 0xB56421D);                //mov r10, [0x00000000060F85DB]
                r11 = mb;          //lea r11, [0xFFFFFFFFFAB943AB]
                rdx = mb + 0x8817;                 //lea rdx, [0xFFFFFFFFFAB9CB65]
                rax ^= rbx;             //xor rax, rbx
                rax -= r11;             //sub rax, r11
                rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
                rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
                rcx ^= r10;             //xor rcx, r10
                rcx = ~rcx;             //not rcx
                rax *= *(uintptr_t*)(rcx + 0x15);                //imul rax, [rcx+0x15]
                rcx = 0x647DC95B2924B45D;               //mov rcx, 0x647DC95B2924B45D
                rax *= rcx;             //imul rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0xF;            //shr rcx, 0x0F
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x1E;           //shr rcx, 0x1E
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x3C;           //shr rcx, 0x3C
                rax ^= rcx;             //xor rax, rcx
                rcx = rbx;              //mov rcx, rbx
                rcx ^= rdx;             //xor rcx, rdx
                rax += rcx;             //add rax, rcx
                rcx = 0x66F54217655405BD;               //mov rcx, 0x66F54217655405BD
                rax *= rcx;             //imul rax, rcx
                return rax;
        }
        case 5:
        {
                r9 = *(uintptr_t*)(mb + 0xB56421D);                 //mov r9, [0x00000000060F80D7]
                r11 = mb;          //lea r11, [0xFFFFFFFFFAB93EA7]
                rcx = rbx;              //mov rcx, rbx
                rcx -= r11;             //sub rcx, r11
                rcx += 0xFFFFFFFFDA207ED1;              //add rcx, 0xFFFFFFFFDA207ED1
                rax += rcx;             //add rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x12;           //shr rcx, 0x12
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x24;           //shr rcx, 0x24
                rax ^= rcx;             //xor rax, rcx
                rcx = rbx;              //mov rcx, rbx
                rcx -= r11;             //sub rcx, r11
                rcx -= 0x39EDAA32;              //sub rcx, 0x39EDAA32
                rax ^= rcx;             //xor rax, rcx
                rcx = 0x24AC8C57718FF261;               //mov rcx, 0x24AC8C57718FF261
                rax *= rcx;             //imul rax, rcx
                rcx = 0x5997D68B6A65573B;               //mov rcx, 0x5997D68B6A65573B
                rax *= rcx;             //imul rax, rcx
                rcx = 0x5FD1C67422180770;               //mov rcx, 0x5FD1C67422180770
                rax -= rcx;             //sub rax, rcx
                rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
                rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
                rcx ^= r9;              //xor rcx, r9
                rcx = ~rcx;             //not rcx
                rax *= *(uintptr_t*)(rcx + 0x15);                //imul rax, [rcx+0x15]
                rcx = rbx;              //mov rcx, rbx
                rcx -= r11;             //sub rcx, r11
                rcx += 0xFFFFFFFFE77DFE7B;              //add rcx, 0xFFFFFFFFE77DFE7B
                rax += rcx;             //add rax, rcx
                return rax;
        }
        case 6:
        {
                r9 = *(uintptr_t*)(mb + 0xB56421D);                 //mov r9, [0x00000000060F7C0E]
                r11 = mb;          //lea r11, [0xFFFFFFFFFAB939DE]
                rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
                rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
                rcx ^= r9;              //xor rcx, r9
                rcx = ~rcx;             //not rcx
                rax *= *(uintptr_t*)(rcx + 0x15);                //imul rax, [rcx+0x15]
                rcx = 0x53AAB2A28C6F8FF0;               //mov rcx, 0x53AAB2A28C6F8FF0
                rax ^= rcx;             //xor rax, rcx
                rax -= rbx;             //sub rax, rbx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x12;           //shr rcx, 0x12
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x24;           //shr rcx, 0x24
                rcx ^= rbx;             //xor rcx, rbx
                rax ^= rcx;             //xor rax, rcx
                rax += r11;             //add rax, r11
                rax += rbx;             //add rax, rbx
                rcx = 0x3EACC212565A3D5;                //mov rcx, 0x3EACC212565A3D5
                rax *= rcx;             //imul rax, rcx
                return rax;
        }
        case 7:
        {
                r10 = *(uintptr_t*)(mb + 0xB56421D);                //mov r10, [0x00000000060F77A8]
                r11 = mb + 0x8FBF;                 //lea r11, [0xFFFFFFFFFAB9C537]
                rcx = mb + 0xD9BA;                 //lea rcx, [0xFFFFFFFFFABA0CED]
                rcx = ~rcx;             //not rcx
                rcx += rbx;             //add rcx, rbx
                rax += rcx;             //add rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x1B;           //shr rcx, 0x1B
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x36;           //shr rcx, 0x36
                rax ^= rcx;             //xor rax, rcx
                rcx = 0xC097FE30215EF7B;                //mov rcx, 0xC097FE30215EF7B
                rax -= rcx;             //sub rax, rcx
                rax += rbx;             //add rax, rbx
                rcx = 0x27217EED83C00465;               //mov rcx, 0x27217EED83C00465
                rax *= rcx;             //imul rax, rcx
                rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
                rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
                rcx ^= r10;             //xor rcx, r10
                rcx = ~rcx;             //not rcx
                rax *= *(uintptr_t*)(rcx + 0x15);                //imul rax, [rcx+0x15]
                rax ^= rbx;             //xor rax, rbx
                rax ^= r11;             //xor rax, r11
                rcx = 0x40FC9A08434EAB8;                //mov rcx, 0x40FC9A08434EAB8
                rax ^= rcx;             //xor rax, rcx
                return rax;
        }
        case 8:
        {
                r9 = *(uintptr_t*)(mb + 0xB56421D);                 //mov r9, [0x00000000060F7388]
                r11 = mb;          //lea r11, [0xFFFFFFFFFAB93158]
                rcx = 0xC640566C96CFB225;               //mov rcx, 0xC640566C96CFB225
                rax *= rcx;             //imul rax, rcx
                rax ^= r11;             //xor rax, r11
                rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
                rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
                rcx ^= r9;              //xor rcx, r9
                rcx = ~rcx;             //not rcx
                rax *= *(uintptr_t*)(rcx + 0x15);                //imul rax, [rcx+0x15]
                rax -= rbx;             //sub rax, rbx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x4;            //shr rcx, 0x04
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x8;            //shr rcx, 0x08
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x10;           //shr rcx, 0x10
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x20;           //shr rcx, 0x20
                rax ^= rcx;             //xor rax, rcx
                rax += rbx;             //add rax, rbx
                rcx = 0x36BE6884C47C6D33;               //mov rcx, 0x36BE6884C47C6D33
                rax *= rcx;             //imul rax, rcx
                rcx = rbx;              //mov rcx, rbx
                rcx = ~rcx;             //not rcx
                rcx -= r11;             //sub rcx, r11
                rcx -= 0x736A3793;              //sub rcx, 0x736A3793
                rax ^= rcx;             //xor rax, rcx
                return rax;
        }
        case 9:
        {
                r10 = *(uintptr_t*)(mb + 0xB56421D);                //mov r10, [0x00000000060F6EA6]
                r13 = mb + 0x56B5;                 //lea r13, [0xFFFFFFFFFAB9832B]
                rcx = rbx;              //mov rcx, rbx
                rcx = ~rcx;             //not rcx
                rcx ^= r13;             //xor rcx, r13
                rax -= rcx;             //sub rax, rcx
                rcx = 0x617EE6B8548ACFF8;               //mov rcx, 0x617EE6B8548ACFF8
                rax ^= rcx;             //xor rax, rcx
                rax += rbx;             //add rax, rbx
                rcx = 0x44AC3A1174A702A7;               //mov rcx, 0x44AC3A1174A702A7
                rax *= rcx;             //imul rax, rcx
                rdx = 0;                //and rdx, 0xFFFFFFFFC0000000
                rax ^= rbx;             //xor rax, rbx
                rdx = _rotl64(rdx, 0x10);               //rol rdx, 0x10
                rcx = rax;              //mov rcx, rax
                rdx ^= r10;             //xor rdx, r10
                rax >>= 0x27;           //shr rax, 0x27
                rdx = ~rdx;             //not rdx
                rax ^= rcx;             //xor rax, rcx
                rax *= *(uintptr_t*)(rdx + 0x15);                //imul rax, [rdx+0x15]
                rcx = 0x7915D47D16706192;               //mov rcx, 0x7915D47D16706192
                rax -= rcx;             //sub rax, rcx
                return rax;
        }
        case 10:
        {
                r9 = *(uintptr_t*)(mb + 0xB56421D);                 //mov r9, [0x00000000060F6A85]
                r11 = mb;          //lea r11, [0xFFFFFFFFFAB92855]
                rcx = mb + 0x5A848877;             //lea rcx, [0x00000000553DAD1A]
                rcx = ~rcx;             //not rcx
                rcx ^= rbx;             //xor rcx, rbx
                rax -= rcx;             //sub rax, rcx
                rcx = 0x21F6FDA360F3B27;                //mov rcx, 0x21F6FDA360F3B27
                rax ^= r11;             //xor rax, r11
                rax *= rcx;             //imul rax, rcx
                rax -= rbx;             //sub rax, rbx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x6;            //shr rcx, 0x06
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0xC;            //shr rcx, 0x0C
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x18;           //shr rcx, 0x18
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x30;           //shr rcx, 0x30
                rax ^= rcx;             //xor rax, rcx
                rcx = 0x3B33D31E5AB12803;               //mov rcx, 0x3B33D31E5AB12803
                rax += rcx;             //add rax, rcx
                rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
                rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
                rcx ^= r9;              //xor rcx, r9
                rcx = ~rcx;             //not rcx
                rax *= *(uintptr_t*)(rcx + 0x15);                //imul rax, [rcx+0x15]
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x26;           //shr rcx, 0x26
                rax ^= rcx;             //xor rax, rcx
                return rax;
        }
        case 11:
        {
                r10 = *(uintptr_t*)(mb + 0xB56421D);                //mov r10, [0x00000000060F65E4]
                rdx = rbx;              //mov rdx, rbx
                rdx = ~rdx;             //not rdx
                rcx = mb + 0x28691EFC;             //lea rcx, [0x0000000023224002]
                rcx = ~rcx;             //not rcx
                rdx += rcx;             //add rdx, rcx
                rax ^= rdx;             //xor rax, rdx
                rcx = 0x4F163BACB48EBF73;               //mov rcx, 0x4F163BACB48EBF73
                rax += rcx;             //add rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x14;           //shr rcx, 0x14
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x28;           //shr rcx, 0x28
                rax ^= rcx;             //xor rax, rcx
                rcx = 0x4127EEFEDE5B92FD;               //mov rcx, 0x4127EEFEDE5B92FD
                rax += rcx;             //add rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x21;           //shr rcx, 0x21
                rax ^= rcx;             //xor rax, rcx
                rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
                rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
                rcx ^= r10;             //xor rcx, r10
                rcx = ~rcx;             //not rcx
                rax *= *(uintptr_t*)(rcx + 0x15);                //imul rax, [rcx+0x15]
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x4;            //shr rcx, 0x04
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x8;            //shr rcx, 0x08
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x10;           //shr rcx, 0x10
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x20;           //shr rcx, 0x20
                rax ^= rcx;             //xor rax, rcx
                rcx = 0x397EFF255639273F;               //mov rcx, 0x397EFF255639273F
                rax *= rcx;             //imul rax, rcx
                return rax;
        }
        case 12:
        {
                r9 = *(uintptr_t*)(mb + 0xB56421D);                 //mov r9, [0x00000000060F60AF]
                r13 = mb + 0x41C6E8B9;             //lea r13, [0x000000003C800738]
                rax += rbx;             //add rax, rbx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x22;           //shr rcx, 0x22
                rax ^= rcx;             //xor rax, rcx
                rcx = 0x233E216C40FA2CDF;               //mov rcx, 0x233E216C40FA2CDF
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x18;           //shr rcx, 0x18
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x30;           //shr rcx, 0x30
                rax ^= rcx;             //xor rax, rcx
                rax ^= rbx;             //xor rax, rbx
                rax ^= r13;             //xor rax, r13
                rcx = 0x6773B66CDA475049;               //mov rcx, 0x6773B66CDA475049
                rax *= rcx;             //imul rax, rcx
                uintptr_t RSP_0xFFFFFFFFFFFFFF97;
                RSP_0xFFFFFFFFFFFFFF97 = 0xF154E6D1B3660D73;            //mov rcx, 0xF154E6D1B3660D73 : RBP+0xFFFFFFFFFFFFFF97
                rax ^= RSP_0xFFFFFFFFFFFFFF97;          //xor rax, [rbp-0x69]
                rcx = 0;                //and rcx, 0xFFFFFFFFC0000000
                rcx = _rotl64(rcx, 0x10);               //rol rcx, 0x10
                rcx ^= r9;              //xor rcx, r9
                rcx = ~rcx;             //not rcx
                rax *= *(uintptr_t*)(rcx + 0x15);                //imul rax, [rcx+0x15]
                return rax;
        }
        case 13:
        {
                r10 = *(uintptr_t*)(mb + 0xB56421D);                //mov r10, [0x00000000060F5BD5]
                r11 = mb;          //lea r11, [0xFFFFFFFFFAB91991]
                rcx = r11 + 0xba17;             //lea rcx, [r11+0xBA17]
                rcx += rbx;             //add rcx, rbx
                rax += rcx;             //add rax, rcx
                rdx = 0;                //and rdx, 0xFFFFFFFFC0000000
                rdx = _rotl64(rdx, 0x10);               //rol rdx, 0x10
                rcx = mb + 0x9610;                 //lea rcx, [0xFFFFFFFFFAB9AC4C]
                rdx ^= r10;             //xor rdx, r10
                rcx = ~rcx;             //not rcx
                rcx -= rbx;             //sub rcx, rbx
                rdx = ~rdx;             //not rdx
                rax += rcx;             //add rax, rcx
                rax *= *(uintptr_t*)(rdx + 0x15);                //imul rax, [rdx+0x15]
                rcx = rax;              //mov rcx, rax
                rdx = mb + 0x102B1DCA;             //lea rdx, [0x000000000AE43596]
                rcx >>= 0x15;           //shr rcx, 0x15
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x2A;           //shr rcx, 0x2A
                rax ^= rcx;             //xor rax, rcx
                rcx = 0x6A8B294107CC0501;               //mov rcx, 0x6A8B294107CC0501
                rax ^= rcx;             //xor rax, rcx
                rcx = 0x2EA5061AACD42452;               //mov rcx, 0x2EA5061AACD42452
                rax -= rcx;             //sub rax, rcx
                rcx = rbx;              //mov rcx, rbx
                rcx = ~rcx;             //not rcx
                rcx ^= rdx;             //xor rcx, rdx
                rax += rcx;             //add rax, rcx
                rcx = 0x4EB7AE4244212391;               //mov rcx, 0x4EB7AE4244212391
                rax *= rcx;             //imul rax, rcx
                return rax;
        }
        case 14:
        {
                r10 = *(uintptr_t*)(mb + 0xB56421D);                //mov r10, [0x00000000060F57B9]
                r11 = mb;          //lea r11, [0xFFFFFFFFFAB91589]
                rax ^= r11;             //xor rax, r11
                rcx = 0xC752E26BA360D032;               //mov rcx, 0xC752E26BA360D032
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x19;           //shr rcx, 0x19
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x32;           //shr rcx, 0x32
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0xD;            //shr rcx, 0x0D
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x1A;           //shr rcx, 0x1A
                rax ^= rcx;             //xor rax, rcx
                rdx = 0;                //and rdx, 0xFFFFFFFFC0000000
                rdx = _rotl64(rdx, 0x10);               //rol rdx, 0x10
                rcx = rax;              //mov rcx, rax
                rdx ^= r10;             //xor rdx, r10
                rcx >>= 0x34;           //shr rcx, 0x34
                rdx = ~rdx;             //not rdx
                rax ^= rcx;             //xor rax, rcx
                rax *= *(uintptr_t*)(rdx + 0x15);                //imul rax, [rdx+0x15]
                rcx = 0x5436A045E6437655;               //mov rcx, 0x5436A045E6437655
                rax ^= r11;             //xor rax, r11
                rax *= rcx;             //imul rax, rcx
                return rax;
        }
        case 15:
        {
                r10 = *(uintptr_t*)(mb + 0xB56421D);                //mov r10, [0x00000000060F5355]
                r11 = mb;          //lea r11, [0xFFFFFFFFFAB91125]
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x6;            //shr rcx, 0x06
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0xC;            //shr rcx, 0x0C
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x18;           //shr rcx, 0x18
                rax ^= rcx;             //xor rax, rcx
                rdx = 0;                //and rdx, 0xFFFFFFFFC0000000
                rdx = _rotl64(rdx, 0x10);               //rol rdx, 0x10
                rdx ^= r10;             //xor rdx, r10
                rcx = rax;              //mov rcx, rax
                rdx = ~rdx;             //not rdx
                rcx >>= 0x30;           //shr rcx, 0x30
                rax ^= rcx;             //xor rax, rcx
                rax *= *(uintptr_t*)(rdx + 0x15);                //imul rax, [rdx+0x15]
                rax += r11;             //add rax, r11
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x24;           //shr rcx, 0x24
                rax ^= rcx;             //xor rax, rcx
                rcx = 0xB6C3A6FE99C92A23;               //mov rcx, 0xB6C3A6FE99C92A23
                rax *= rcx;             //imul rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x9;            //shr rcx, 0x09
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x12;           //shr rcx, 0x12
                rax ^= rcx;             //xor rax, rcx
                rcx = rax;              //mov rcx, rax
                rcx >>= 0x24;           //shr rcx, 0x24
                rax ^= rcx;             //xor rax, rcx
                rcx = 0xD7420EB04571AACF;               //mov rcx, 0xD7420EB04571AACF
                rax *= rcx;             //imul rax, rcx
                rcx = 0x578A3A3D4AF2D633;               //mov rcx, 0x578A3A3D4AF2D633
                rax += rcx;             //add rax, rcx
                return rax;
        }
        }
};